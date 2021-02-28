TARGET := inputfile
SOURCE_CPP = $(SDIR)/main.cpp
SOURCE_OBJ = $(ODIR)/main.o
CXX = g++

$(TARGET): $(SOURCE_OBJ)
	${CXX} $(SOURCE_OBJ) -o $(TARGET)

$(SOURCE_OBJ):
	${CXX} -c $(SOURCE_CPP) -o $(SOURCE_OBJ)

clean:
	rm $(SOURCE_OBJ) $(TARGET) 

