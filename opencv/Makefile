OPENCV=`/opt/local/bin/pkg-config --cflags --libs opencv`

all:
	rm -rf bin/
	mkdir bin
	gcc 01-load.c -o bin/01-load $(OPENCV)
	gcc 02-blur.c -o bin/02-blur $(OPENCV)
	gcc 03-resize.c -o bin/03-resize $(OPENCV)
	gcc 04-drawing.c -o bin/04-drawing $(OPENCV)
	gcc 05-save.c -o bin/05-save $(OPENCV)
