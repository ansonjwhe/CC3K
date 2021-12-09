CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = CC3K
OBJECTS = main.o game.o floor.o cell.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
