CXX = g++
CXXFLAGS = -Werror=vla -g -Wall -MMD
OBJECTS = main.o cell.o grid.o textdisplay.o subject.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a4q3

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies

