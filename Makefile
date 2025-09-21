# Paths
INCLUDE_DIR = C:/Softwares/mingw64/include
LIB_DIR = C:/Softwares/mingw64/lib

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Wunused -Wpedantic -Wuninitialized -std=c++23 -I$(INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR) -lmingw32 -lSDL3_image -lSDL3 $(LIB_DIR)/libSDL3.dll.a

# Folders
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = build
TARGET = $(BIN_DIR)/LPPO.exe

# Source and object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	@echo Linking...
	$(CXX) -o $@ $^ $(LDFLAGS)
	@echo Done!
# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo Compiling $<...
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create directories
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Make sure both dirs exist before building
$(TARGET): | $(BIN_DIR)

# Clean
clean:
	@echo "OK"
	-rm obj/*

.PHONY: all clean
