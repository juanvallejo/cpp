OBJS = project2.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall $(DEBUG)

clean:
	\rm *.o && rm OutputArray.txt && rm -r ./build 2>&1>/dev/null

rmoutput:
	rm OutputArray.txt && Output.txt 2>&1>/dev/null

all: project movebuild

project: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o project

project2.o:
	$(CC) $(CFLAGS) project2.cpp

movebuild:
	mkdir -p ./build && mv *.o ./build && mv project build

run: all
	./build/project