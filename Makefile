CFLAGS := -g
INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm


all: project inputtest outputtest
	./project

project: main.o input.o output.o
	gcc -o project $(INCLUDE) main.o $(LDFLAGS) input.o $(LDFLAGS) output.o $(LDFLAGS)

%.o: %.c project.h
	gcc -c $(CLFAGS) $< $(INCLUDE) 

clean: clear
	rm project outputtest inputtest *.o

clear: clearDisp.c FORCE
	gcc -o clear $(INCLUDE) clearDisp.c $(LDFLAGS)
	./clear
	rm clear

outputtest: outputtest.o output.o
	gcc -o outputtest $(INCLDUE)  outputtest.o $(LDFLAGS) output.o $(LDFLAGS)

inputtest: inputtest.o input.o
	gcc -o inputtest $(INCLUDE) inputtest.o $(LDFLAGS) input.o $(LDFLAGS)

FORCE:
