.PHONY: clean create_dir
CXX := g++
TOP := ../../
TARGET := fibonachi
BIN_DIR := $(TOP)/bin/$(TARGET)
SRC := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))

$(TARGET):$(OBJ)
	$(CXX) $(OBJ) -o $(BIN_DIR)/$(TARGET)
%.o: %.cpp $(HEADERS) create_dir
	$(CXX) -c $< -o $@
create_dir:
	mkdir -p $(BIN_DIR) 
clean:
	rm -rf $(BIN_DIR)
	rm -rf *.o
