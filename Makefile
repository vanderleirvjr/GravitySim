# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Directories
SRC_DIR = src
INCLUDE_DIR = include
STRUCTS_DIR = include/structs
OBJ_DIR = obj
BIN_DIR = bin

# HDF5 directories
NETCDF_INCLUDE = $(NETCDF)/include
NETCDF_LIB = $(NETCDF)/lib/aarch64-linux-gnu

# Source and Object files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# Target
TARGET = $(BIN_DIR)/program

# Make rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ -L$(NETCDF_LIB) -lnetcdf -lnetcdf_c++4

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -I$(STRUCTS_DIR) -I$(NETCDF_INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
