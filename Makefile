# Variables
CXXFLAGS = -Wall -Wextra -Iinclude

SRCDIR = src/
INCLDIR = include/
BUILDDIR = build/

# Default
all: my_snake

# Main program
my_snake: $(BUILDDIR)main.o
		g++ $(CXXFLAGS) $(BUILDDIR)main.o -o my_snake

# Rules for .o files
$(BUILDDIR)main.o: $(SRCDIR)main.cpp $(INCLDIR)point.h $(INCLDIR)snake.h $(BUILDDIR)
		g++ $(CXXFLAGS) -c $(SRCDIR)main.cpp -o $(BUILDDIR)main.o

# Other rules
$(BUILDDIR):
		mkdir build

clean: 
		rm -rf $(BUILDDIR)

play: my_snake
		./my_snake

# Mark targets that aren't files
.PHONY: all clean