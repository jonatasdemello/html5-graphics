/*
From jeffb@sware.com Fri Apr 26 21:59:02 PDT 1996
Article: 307 of isaac.lists.coderpunks
Path: news.isaac.cs.berkeley.edu!not-for-mail
From: Jeff Barber <jeffb@sware.com>
Newsgroups: isaac.lists.coderpunks
Subject: Noise sphere plotter in C for X Windows
Date: 28 Mar 1996 09:17:05 -0800
Organization: ISAAC Group, UC Berkeley
Lines: 225
Sender: bin@abraham.cs.berkeley.edu
Approved: mail2news@news.isaac.cs.berkeley.edu
Distribution: isaac
Message-ID: <199603281506.KAA10317@jafar.sware.com>
References: <199603250551.AAA22514@unix.asb.com>
NNTP-Posting-Host: abraham.cs.berkeley.edu
Mime-Version: 1.0
Content-Type: text/plain; charset=US-ASCII
Content-Transfer-Encoding: 7bit
In-Reply-To: <199603250551.AAA22514@unix.asb.com> from "Mutatis Mutantdis" at Mar 25, 96 05:38:32 am
X-Mailer: ELM [version 2.4 PL24]
Precedence: bulk

Mutatis Mutantdis writes:

> >I've got a short program for the PC (w/TPascal source) that plots a
> >noise sphere from a file of (pseudo) random data, if anyone is
> >interested.  Requires a VGA card that handles mode 5Fh (640 x 480,
> [..]
> >The source has a brief explanation of what noise spheres are and a
> >reference to the Pickover article the program was based on.

> Somebody sent me a C++ conversion of it. It compiles fine with BCC 4.02.
>
> Enclosed here (thanks to  "James Pate Williams, Jr." <pate@mindspring.com>)

Here's a version of it for X Windows, translated into plain-old C.


-- Jeff
                                 oo
-----------------------------cut /\ here------------------------------
*/
/*
  xnoisesph.c

  Compiled on Linux with:
  	cc -o xnoisesph xnoisesph.c -L /usr/X11R6/lib -lX11 -lm

  Usage: xnoisesph file
  Or:    xnoisesph <file

  Based on:

  NOISESPH.PAS, A Noise Sphere plotter written in Turbo Pascal (23-Mar-96)
  Robert Rothenburg Walking-Owl <WlkngOwl@unix.asb.com>
  No copyright is claimed.  No guarantees made.

  Usage: noisesph file

  This program reads a file of random or pseudo-random data and plots
  a noise sphere of the data. Poor RNGs or sampling methods will show
  clear patterns (definite splotches or spirals).

  The theory behind this is to get a set of 3D polar coordinates from
  the RNG and plot them.  An array is kept of the values, which is
  rotated each time a new byte is read (see the code in the main
  procedure).

  Rather than plot one sphere which can be rotated around any axis,
  it was easier to plot the sphere from three different angles.

  This program is based on a description from the article below.  It
  was proposed as a means of testing pseudo-RNGs:

  Pickover, Clifford A. 1995. "Random number generators: pretty good
	 ones are easy to find."  The Visual Computer (1005) 11:369-377.
*/

#include <X11/Xlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <unistd.h>

typedef struct _Cartesian {
  double x, y, z;
  unsigned Color;
} Cartesian;

typedef struct _Polar {
  double r, theta, phi;
} Polar;

double ByteToReal(unsigned char);
unsigned int ScaleColor(double);
int Round(double);
void Plot(Cartesian *);
void PolarToCartesian(Polar *, Cartesian *);

int MidA, MidB, MidC, MidY, Scale;

char *pgm;
Window w;
Display *d;
GC gc;

void
main(int ac, char **av)
{
    int i;
    char *fname;
    FILE *inp;
    XEvent event;
    XExposeEvent *ee = (XExposeEvent *)&event;
    int width, height, bwidth, depth, wx, wy;
    Window root;

    pgm = basename(*av);
    if (ac > 2) {
	fprintf(stderr, "Usage: %s [file]\n", pgm);
	exit(1);
    }

    if (ac == 2) {
	fname = av[1];
	if ((inp = fopen(fname, "rb")) == NULL) {
	    fprintf(stderr, "%s: Can't open %s - %s\n", pgm, av[1],
	    	strerror(errno));
	    exit(1);
	}
    }
    else {
    	inp = stdin;
    	fname = "(stdin)";
    }

    if (!(d = XOpenDisplay(NULL)))
    {
	fprintf(stderr, "%s: Can't open display\n", pgm);
	exit(1);
    }

    w = XCreateSimpleWindow(d, RootWindow(d, DefaultScreen(d)),
	0, 0, 640, 480, 0, BlackPixel(d, DefaultScreen(d)),
	BlackPixel(d, DefaultScreen(d)));

    XSelectInput(d, w, ExposureMask);

    gc = XCreateGC(d, w, 0L, NULL);
    XSetBackground(d, gc, BlackPixel(d, DefaultScreen(d)));
    XSetForeground(d, gc, WhitePixel(d, DefaultScreen(d)));

    XMapRaised(d, w);

    while (XNextEvent(d, &event), event.type != Expose)
    	;

    /*
     * Get the window's actual width and height.
     */
    XGetGeometry(d, w, &root, &wx, &wy, &width, &height, &bwidth, &depth);

    /*
     * Initialization done, window on screen; time for real work.
     */

    {
	double X[3];
	int i, n = 0;
	int byte;
	Cartesian C;
	Polar P;

	Scale = width / 6;
	MidA = Scale;
	MidB = 3 * Scale;
	MidC = 5 * Scale;
	MidY = height / 2;
	if (MidY < Scale)
	    Scale = MidY;

	for (i = 0; i < 3; i++) {
	    if ((byte = getc(inp)) == EOF) {
		fprintf(stderr, "%s: Early EOF on %s\n", pgm, fname);
		exit(1);
	    }
	    X[i] = ByteToReal((unsigned char) byte);
	}

	while (1) {
	    P.r = sqrt(X[(n + 2) % 3]);
	    P.theta = M_PI * X[(n + 1) % 3];
	    P.phi = 2 * M_PI * X[n];
	    PolarToCartesian(&P, &C);
	    Plot(&C);
	    if ((byte = getc(inp)) == EOF)
	    	break;
	    X[n] = ByteToReal((unsigned char) byte);
	    n = (n + 1) % 3;
	}
    }

    /*
     * Now hang out.  Let the window manager kill us.
     */
    while (1)
	XNextEvent(d, &event);

    exit(0);
}

double ByteToReal(unsigned char b)
{
  /*note that there will be some gaps since we're only using the
	 equivalent of an 8-bit decimal here*/
  return  b / 256.0;
}

unsigned int ScaleColor(double x)
{
  return 0;
}

int Round(double x)
{
  return (int) (x + 0.5);
}

void Plot(Cartesian *C)
{
    XDrawPoint(d, w, gc, MidA + Round(Scale * C->y),
    			MidY - Round(Scale * C->z));
    XDrawPoint(d, w, gc, MidB + Round(Scale * C->x),
    			MidY - Round(Scale * C->y));
    XDrawPoint(d, w, gc, MidC + Round(Scale * C->z),
    			MidY - Round(Scale * C->x));
}

void PolarToCartesian(Polar *P, Cartesian *C)
{
  /* No rotation was added. Instead we plot from three angles... */
  C->x = P->r * sin(P->phi) * cos(P->theta);
  C->y = P->r * sin(P->phi) * sin(P->theta);
  C->z = P->r * cos(P->phi);
  /* We can assign colors based on x, y, z, r, theta / pi or phi / (2 * pi) */
  C->Color = ScaleColor(C->y);
}



