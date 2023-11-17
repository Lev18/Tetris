# Compiler
CXX=g++

# Flags
CXXFLAGS=-std=c++11 -Wall -I include

# SFML libraries
SFML_LIBRARIES=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Directories
SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
FONT_DIR=Font
MUSIC_DIR=music

# Files
SRC:=$(wildcard $(SRC_DIR)/*.cpp)
OBJ:=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
EXECUTABLE:=$(BIN_DIR)/tetris

# Target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
		@mkdir -p $(BIN_DIR)
		$(CXX) $(CXXFLAGS) $^ -o $@ $(SFML_LIBRARIES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		@mkdir -p $(OBJ_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
