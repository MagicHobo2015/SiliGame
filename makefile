# my compiler, my choice
CXX = g++
OBJFLAGS = -c -Wall -g
OBJECTS = main.o gameBoard.o # list of all the obj files to watch
OUT_FILE = sili # final binary name 
LIBS=-lSDL2 -lSDL2main

# build output
${OUT_FILE}: ${OBJECTS} 
	${CXX} ${OBJECTS} ${LIBS} -o ${OUT_FILE}

# build main.o
main.o: main.cpp gameBoard.cpp
	${CXX} ${OBJFLAGS} $?


clean:
	${RM} *.o ${OUT_FILE}