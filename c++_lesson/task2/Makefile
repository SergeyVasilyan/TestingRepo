TARGET := program
SOURCE_CPP = log_parser.cpp
SOURCE_OBJ = log_parser.o
FLAG = -std=c++11
CXX = g++

$(TARGET): $(SOURCE_OBJ)
	${CXX} $(FLAG) $(SOURCE_OBJ) -o $(TARGET)

$(SOURCE_OBJ):
	 ${CXX} -c $(FLAG) log_parser.cpp -o log_parser.o

.PHONY: clean
clean:
	rm $(SOURCE_OBJ) $(TARGET)
