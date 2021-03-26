# _*_ MakeFile _*_
ROOT=$(dir $(realpath $(firstword $(MAKEFILE_LIST))))
CXX=/usr/bin/g++
CC=gcc
INC=-I$(ROOT)include
LIBS= -lstdc++
FLAGS= -w -g

SRC := $(ROOT)src
OBJ := $(ROOT)obj
BIN := $(ROOT)bin
TARGET := $(BIN)/banking
SOURCES := $(wildcard $(SRC)/*.cpp)
OBJECTS := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SOURCES))

all: | makedirs $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

$(OBJECTS): $(SOURCES)
	$(CXX) $(FLAGS) $(LIBS) $(INC) -c $< -o $@

makedirs:
	-mkdir -p $(OBJ) $(BIN)

.PHONY: all clean

clean:
	rm -rf $(BIN) $(OBJ)
