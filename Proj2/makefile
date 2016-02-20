# Declaration of variables
CC = g++
CC_FLAGS = -w -std=c++11

# File names
EXEC = cracker
SOURCES = main.cpp Executive.cpp BinarySearchTree.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) -pthread

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
