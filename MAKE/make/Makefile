SDIR := ./src
ODIR := $(SDIR)/obj
BINDIR := ./bin
SOURCES:= $(wildcard $(SDIR)/*.cpp)
OBJECTS:= $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SOURCES))
CXX = g++

$(BINDIR)/program: $(0DIR) $(OBJECTS)
	${CXX} $(OBJECTS) -o $(BINDIR)/program

$(ODIR)/%.o: $(SDIR)/%.cpp
	${CXX} -c $< -o $@
clean:
	rm $(OBJECTS) $(BINDIR)/program
dir:
	@mkdir -p $(ODIR)
	@mkdir -p $(BINDIR)

valgrind:
	valgrind --leak-check=full -v ./program
