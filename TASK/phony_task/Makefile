CXX = g++
TARGET := clean

$(TARGET): $(TARGET).o
	${CXX} $(TARGET).o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp
	${CXX} -c $< -o $@

.PHONY: clean
clean:
	rm $(TARGET) $(TARGET).o

