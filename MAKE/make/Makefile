SOURCES := main.cpp add.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))

program : $(OBJECTS)
    g++ $(OBJECTS) -o program
main.o : 
    g++ -c main.cpp -o main.o
add.o : 
    g++ -c add.cpp -o add.o
clean:
    rm *.o program
