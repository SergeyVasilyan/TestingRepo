.PHONY: clean
CXX := g++
SRC_DIR := ../src
BIN_DIR := ../bin
OBJ_DIR := ../obj
OTP_DIR := ../outputs
SRC := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)
OBJ := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
TARGET := convolution
$(BIN_DIR)/$(TARGET):$(OBJ)
	$(CXX) $(OBJ) -o $(BIN_DIR)/$(TARGET)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) -c $< -o $@
clean:
	rm -rf $(BIN_DIR)/*
	rm -rf $(OBJ_DIR)/*
	rm -rf $(OTP_DIR)/*
