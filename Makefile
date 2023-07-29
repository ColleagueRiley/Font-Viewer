all:
	gcc source/main.c -lX11 -lGLX -lm -I./ -o RSGL-Font-Viewer
	./RSGL-Font-Viewer /usr/share/fonts/TTF/DejaVuSans-Bold.ttf