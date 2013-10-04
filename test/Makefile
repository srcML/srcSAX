##
# Makefile

TESTS=$(shell ls *.cpp)
GEN_ALL= ${foreach nm, ${TESTS}, $(nm).out}

all : ${GEN_ALL}

%.cpp.out : %.cpp
	g++ -I . -I ../src/ -I /usr/include/libxml2 $< ../src/*.cpp -lxml2 -o $@ 

run : ${GEN_ALL}
	ls *.out | xargs -t -I% bash -c "./%"

clean : 
	rm *.out
