CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
INCLUDEFLAGS = -I.

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
LIBDIR = ./lib

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst ./src%,./obj%, $(patsubst %.cpp, %.o, $(SOURCES)))

TARGET = $(BINDIR)/project.out

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDEFLAGS) -c $< -o $@

clean:
	rm -rf obj/*
	rm -f $(TARGET)