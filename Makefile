# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Target executable name
TARGET = mergesort

# Build target
$(TARGET): mergesort.cpp
	$(CXX) $(CXXFLAGS) mergesort.cpp -o $(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)
