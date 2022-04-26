CXX = g++
CXXFLAGS = -Werror=vla -g -Wall -MMD
OBJECTS = a4q1.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a4q1

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
