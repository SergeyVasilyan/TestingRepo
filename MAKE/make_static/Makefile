SDIR := ./src
ODIR := $(SDIR)/obj
BINDIR := ./bin
SOURCES:= $(wildcard $(SDIR)/*.cpp)
OBJECTS:= $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SOURCES))
CXX = g++
TARGET := program

$(BINDIR)/$(TARGET): $(0DIR) $(OBJECTS)
	${CXX} $(OBJECTS) -o $(BINDIR)/$(TARGET)

$(OBJECTS): $(SOURCES)
	${CXX} -c $< -o $@
clean:
	rm $(OBJECTS) $(BINDIR)/$(TARGET)
dir:
	@mkdir -p $(ODIR)
	@mkdir -p $(BINDIR)

valgrind:
	valgrind --leak-check=full -v $(BINDIR)/$(TARGET)
