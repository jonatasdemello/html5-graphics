# clean
rm -f ./xnoisesph.out 

# build
gcc -Wall -Wno-pointer-sign -g xnoisesph.c -o xnoisesph.out -L/usr/lib/x86_64-linux-gnu -lX11 -lm

# /usr/lib/x86_64-linux-gnu/libX11.a
# gcc hello-x.c -L/usr/X11R6/lib -lX11 -o hello-x
# gcc -Wall -Wno-pointer-sign -g xnoisesph.c -o xnoisesph.out -L/usr/lib/x86_64-linux-gnu -lX11 -lm
# cc prog.c -o prog -L/usr/X11/lib -lX11

# run
./xnoisesph.out ./rng-out.bin

