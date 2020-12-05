# _*_ MakeFile _*_
ROOT=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))
CXX=/usr/bin/g++
CC=gcc
INC=-I$(ROOT)include
LIBS= -lstdc++
FLAGS= -w -g

SRC := $(ROOT)src
OBJ := $(ROOT)obj
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))

compile: | makedirs $(ROOT)bin/banking

$(ROOT)bin/banking: $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

makedirs: $(ROOT)obj/ $(ROOT)bin/
	-mkdir -p $(ROOT)obj $(ROOT)bin

copyconfig: config.cfg
	$(shell cp ./config.cfg ./bin)

$(ROOT)obj/%.o: $(ROOT)src/%.cpp $(ROOT)include/%.hpp
	$(CXX) -c $(INC) $(LIBS) $(FLAGS) $< -o $@

.PHONY: clean

clean:
	rm -rf $(ROOT)obj/* $(ROOT)bin/*
