# my compiler choice
CXX = clang++
CXXFLAGS = -std=c++20
OBJFLAGS = -c
OBJECTS = main.o # list of all the obj files to watch
OUT_FILE = sili # final binary name 

# build output
${OUT_FILE}: ${OBJECTS} 
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${OUT_FILE}

# build main.o
main.o: main.cpp
	${CXX} ${CXXFLAGS} ${OBJFLAGS} main.cpp


clean:
	${RM} *.o ${OUT_FILE}