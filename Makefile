# filepath: /podman-container-project/podman-container-project/Makefile
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Target binary
TARGET = helloworld

# Source files
SRCS = src/helloworld.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean