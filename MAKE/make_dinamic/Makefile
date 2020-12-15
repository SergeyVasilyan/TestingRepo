SDIR := ./src
ODIR := $(SDIR)/obj
BINDIR := ./bin
SOURCES:= $(wildcard $(SDIR)/*.cpp)
OBJECTS:= $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(SOURCES))
CXX = g++
TARGET := program
CFLAGS := -fPIC

$(BINDIR)/$(TARGET): $(0DIR) $(OBJECTS) lib
	${CXX} $(ODIR)/main.o $(BINDIR)/libmylib.so -o $(BINDIR)/$(TARGET)

$(ODIR)/%.o: $(SDIR)/%.cpp
	${CXX} -c $< -o $@
clean:
	@rm $(OBJECTS) $(BINDIR)/$(TARGET)
dir:
	@mkdir -p $(ODIR)
	@mkdir -p $(BINDIR)

valgrind:
	valgrind --leak-check=full -v $(BINDIR)/$(TARGET)

lib: $(ODIR) $(OBJECT)
	$(CXX) -shared $(CFLAGS) -o $(BINDIR)/libmylib.so  $(ODIR)/add.o

