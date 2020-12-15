SRC_DIR:=./src
OBJ_DIR:=$(SRC_DIR)/obj
BIN_DIR:=./bin
SRC:= $(wildcard $(SRC_DIR)/*.cpp) 
OBJ:=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
CXX:=g++
TARGET:=main

main: $(OBJ) $(BIN_DIR) 
	$(CXX) $(OBJ) -o $(BIN_DIR)/$(TARGET)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp create_dir
	$(CXX) -c $< -o $@
create_dir:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
valgrind:
	valgrind --leak-check=full -v $(BIN_DIR)/$(TARGET)
clean:
	@rm $(BIN_DIR)/$(TARGET)
	@rm $(OBJ_DIR)/*.o 
