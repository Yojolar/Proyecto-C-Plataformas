ALL: BUILD RUN CLEAN

BUILD:
	gcc `pkg-config --cflags gtk+-3.0` Proyecto_C.c -o gato `pkg-config --libs gtk+-3.0`

RUN:
	./gato

CLEAN:
	