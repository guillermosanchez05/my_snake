# ---- VARIABLES ----

# Compilation
CXX = g++
CXXFLAGS = -Wall -Wextra -g -I$(INC_DIR)

# Files
TARGET = $(BIN_DIR)my_snake

# Directories
SRC_DIR = src/
INC_DIR = include/
BUILD_DIR = build/
BIN_DIR = bin/


# ---- RULES ----

all: $(TARGET)
	
# Executable	
$(TARGET): $(BUILD_DIR)main.o $(BUILD_DIR)board.o $(BUILD_DIR)snake.o $(BUILD_DIR)food.o
	mkdir -p $(BIN_DIR)
	$(CXX) $(BUILD_DIR)main.o $(BUILD_DIR)board.o $(BUILD_DIR)snake.o $(BUILD_DIR)food.o -o $(TARGET) -lncurses

# main.o
$(BUILD_DIR)main.o: $(SRC_DIR)main.cpp $(INC_DIR)snake.h $(INC_DIR)board.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)main.cpp -o $(BUILD_DIR)main.o

# board.o
$(BUILD_DIR)board.o: $(SRC_DIR)board.cpp $(INC_DIR)board.h $(INC_DIR)coord.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)board.cpp -o $(BUILD_DIR)board.o

# snake.o
$(BUILD_DIR)snake.o: $(SRC_DIR)snake.cpp $(INC_DIR)snake.h $(INC_DIR)coord.h $(INC_DIR)food.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)snake.cpp -o $(BUILD_DIR)snake.o

# food.o
$(BUILD_DIR)food.o: $(SRC_DIR)food.cpp $(INC_DIR)food.h $(INC_DIR)coord.h $(INC_DIR)board.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)food.cpp -o $(BUILD_DIR)food.o

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

run: $(TARGET)
	./$(TARGET)

# Not real files
.PHONY: all clean run
