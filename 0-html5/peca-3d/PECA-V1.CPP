/*
   Programa em 3D que desenha uma peca
   Autor : Jonatas de Mello
   data: 1994-09-01
*/

#define nv 48
#define na 72

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

// Estruturas de dados e Variaveis

// cada ponto da figura (x, y, z)
typedef float Ponto[3];
// os vertices que ligam os pontos (x, y, cor)
typedef int Vert[3];
// uma figura é composta por pontos e vertices
typedef struct FiguraTag {
	Ponto pt[nv];
	Vert  vt[na];
} Figura;

float xt[nv], yt[nv]; // X, Y tela
float xv, yv, zv; // X, Y, Z view

Figura fg = {
	{ // 48 vértices (X, Y, Z)
		{0  , 0  , 0}, {10 , 0  , 0}, {10 , 6  , 0}, {0  , 6  , 0}, {0  , 0  , 1}, {10 , 0  , 1}, {10 , 6  , 1}, {0  , 6  , 1},
		{4.3, 1.2, 1}, {5.7, 1.2, 1}, {6.8, 2.2, 1}, {6.8, 3.8, 1}, {5.7, 4.8, 1}, {4.3, 4.8, 1}, {3.2, 3.8, 1}, {3.2, 2.2, 1},
		{4.5, 1.8, 1}, {5.5, 1.8, 1}, {6.2, 2.5, 1}, {6.2, 3.5, 1}, {5.5, 4.2, 1}, {4.5, 4.2, 1}, {3.8, 3.5, 1}, {3.8, 2.5, 1},
		{4.3, 1.2, 5}, {5.7, 1.2, 5}, {6.8, 2.2, 5}, {6.8, 3.8, 5}, {5.7, 4.8, 5}, {4.3, 4.8, 5}, {3.2, 3.8, 5}, {3.2, 2.2, 5},
		{4.5, 1.8, 5}, {5.5, 1.8, 5}, {6.2, 2.5, 5}, {6.2, 3.5, 5}, {5.5, 4.2, 5}, {4.5, 4.2, 5}, {3.8, 3.5, 5}, {3.8, 2.5, 5},
		{1.7, 2.2, 1}, {8.3, 2.2, 1}, {8.3, 3.8, 1}, {1.7, 3.8, 1}, {3.2, 2.2, 3}, {6.8, 2.2, 3}, {6.8, 3.8, 3}, {3.2, 3.8, 3}
	},
	{  // 72 arestas (p1,  p2,  cor)
		{0 , 1 , 2}, {1 , 2 , 2}, {2 , 3 , 2}, {3 , 0 , 2}, {4 , 5 , 2}, {5 , 6 , 2}, {6 , 7 , 2}, {7 , 4 , 2},
		{0 , 4 , 2}, {1 , 5 , 2}, {2 , 6 , 2}, {3 , 7 , 2}, {8 , 9 , 3}, {9 , 10, 3}, {10, 11, 3}, {11, 12, 3},
		{12, 13, 3}, {13, 14, 3}, {14, 15, 3}, {15, 8 , 3}, {24, 25, 3}, {25, 26, 3}, {26, 27, 3}, {27, 28, 3},
		{28, 29, 3}, {29, 30, 3}, {30, 31, 3}, {31, 24, 3}, {8 , 24, 3}, {9 , 25, 3}, {10, 26, 3}, {11, 27, 3},
		{12, 28, 3}, {13, 29, 3}, {14, 30, 3}, {15, 31, 3}, {16, 17, 3}, {17, 18, 3}, {18, 19, 3}, {19, 20, 3},
		{20, 21, 3}, {21, 22, 3}, {22, 23, 3}, {23, 16, 3}, {32, 33, 3}, {33, 34, 3}, {34, 35, 3}, {35, 36, 3},
		{36, 37, 3}, {37, 38, 3}, {38, 39, 3}, {39, 32, 3}, {16, 32, 3}, {17, 33, 3}, {18, 34, 3}, {19, 35, 3},
		{20, 36, 3}, {21, 37, 3}, {22, 38, 3}, {23, 39, 3}, {40, 15, 1}, {10, 41, 1}, {41, 42, 1}, {42, 11, 1},
		{14, 43, 1}, {43, 40, 1}, {40, 44, 1}, {41, 45, 1}, {42, 46, 1}, {43, 47, 1}, {47, 44, 1}, {45, 46, 1}
	}
};

int calcula(int xv, int yv, int zv)
{
	// xv, yv, zv, => coordenadas do observador.
	float a, b, k1, k2, k3, k4, k5;
	float kx, ky, k;
	float x, y, z, la;
	float xin, xax, yin, yax, xmed, ymed;
	int i=0;

	// Calculo das constantes (Geometria Analítica)
	a = sqrt(xv * xv + yv * yv);
	b = sqrt(xv * xv + yv * yv + zv * zv);
	k1 = -yv / a;
	k2 = xv / a;
	k3 = -xv * zv / (a * b);
	k4 = -yv * zv / (a * b);
	k5 = a / b;

	// Calculo para projeção na tela
	for (i = 0; i < nv; i = i + 1)
	{
		la = a * a + 1 / (xv * (fg.pt[i][0] - xv) + yv * (fg.pt[i][1] - yv) + zv * (fg.pt[i][2] - zv));
		x = xv + la * (fg.pt[i][0] - xv);
		y = yv + la * (fg.pt[i][1] - yv);
		z = zv + la * (fg.pt[i][2] - zv);

		xt[i] = (int) (k1 * x + k2 * y);
		yt[i] = (k3 * x + k4 * y + k5 * z);
	}

	// ajustar ao tamanho da tela
	xin = fg.pt[1][0];
	xax = fg.pt[1][0];
	yin = fg.pt[1][1];
	yax = fg.pt[1][1];

	for (i = 0; i < nv; i = i + 1)
	{
		if (xin > xt[i]) xin = xt[i];
		if (xax < xt[i]) xax = xt[i];
		if (yin > yt[i]) yin = yt[i];
		if (yax < yt[i]) yax = yt[i];
	}

	xmed = (xax + xin) / 2;
	ymed = (yax + yin) / 2;

	kx = 600 / (xax - xin);
	ky = 400 / (yax - yin);

	k = ky;
	if (kx < ky) {
		k = kx; 
	}

	x = (600 - (xax - xin) * k) / 2;

	// ajuste horizontal e vertical
	for (i = 0; i < nv; i = i + 1)
	{
		xt[i] = (xt[i] - xin) * k + x;
		yt[i] = 400 - (yt[i] - yin) * k;
	}
	return 0;
}

int desenha()
{
	int i=0;
	int x1, x2, y1, y2, cor;
	for (i = 0; i < na; i = i + 1)
	{
		// setcolor(fg.vt[i][2]);
		// line(xt[fg.vt[i][0]], yt[fg.vt[i][0]], xt[fg.vt[i][1]], yt[fg.vt[i][1]]);

		x1 = xt[fg.vt[i][0]];
		y1 = yt[fg.vt[i][0]];
		x2 = xt[fg.vt[i][1]];
		y2 = yt[fg.vt[i][1]];
		cor = fg.vt[i][2];
		
		setcolor(cor);
		line(x1, y1, x2, y2);
	}
	return 0;
}

int read_input()
{
	int inc = 5;
	int c;

	puts("Q,A, W,S E,D X-END: ");
	c = getch();

	if (c == 65 || c == 113) xv = xv + inc; // A$ = "Q" THEN XV = XV + 10
	if (c == 81 || c == 97 ) xv = xv - inc; // A$ = "A" THEN XV = XV - 10
	if (c == 87 || c == 119) yv = yv + inc; // A$ = "W" THEN YV = YV + 10
	if (c == 83 || c == 115) yv = yv - inc; // A$ = "S" THEN YV = YV - 10
	if (c == 69 || c == 101) zv = zv + inc; // A$ = "E" THEN ZV = ZV + 10
	if (c == 68 || c == 100) zv = zv - inc; // A$ = "D" THEN ZV = ZV - 10
	if (c == 88 || c == 120) return 0; // A$ = "X" THEN END
	return 1;
}

void main()
{
	//float lixo=sin(0); // some trick for Turbo-C/Borland-C?
	int resp = 1;

	int driver, modo;
	detectgraph(&driver, &modo);
	initgraph(&driver, &modo,"c:\\tc\\bgi");

	//cleardevice();
	// printf("Coordenadas do observador \n (X, Y, Z) = ");
	// scanf("%d %d %d", &xv, &yv, &zv);
	// cleardevice();

	xv=0; yv=20; zv=10;
	do
	{
		cleardevice();
		calcula(xv, yv, zv);
		desenha();
		resp = read_input();
	} while (resp != 0);
	
	getch();
	closegraph();
}

