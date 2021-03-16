CXX = g++
CXXFLAGS = -std=c++11
SRCS = main.cpp Space.cpp Line.cpp Eraser.cpp Refill.cpp Pop.cpp Blow.cpp Board.cpp Draw.cpp getInteger.cpp Game.cpp Menu.cpp 

output : ${SRCS}
	${CXX} ${CXXFLAGS} ${SRCS} -o output

debug : ${SRCS}
	${CXX} ${CXXFLAGS} ${SRCS} -g

leak :
	valgrind --leak-check=full ./output
clean : 
	rm output
zip : 
	zip -D Final_Liao_YiChang.zip ${SRCS} ${patsubst %.cpp,%.hpp,$(SRCS)} makefile design_doc.pdf
