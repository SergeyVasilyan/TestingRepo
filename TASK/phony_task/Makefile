CXX = g++
TARGET := program

$(TARGET): main.o add.o
	${CXX} main.o add.o -o $(TARGET)
$(TARGET).o: $(TARGET).cpp
	${CXX} -c main.cpp -o main.o
	${CXX} -c add.cpp -o add.o
.PHONY: clean
clean:
	rm $(TARGET) main.o add.o
