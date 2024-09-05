CXX = g++
CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
BUILD_DIR = build
TARGET = HKNGameEngine

# Find all .cpp files in the current directory
SRCS = $(wildcard *.cpp)
# Generate .o files corresponding to each .cpp file
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Ensure the build directory exists before compiling
$(TARGET): $(BUILD_DIR)/$(TARGET)

# Link all object files to create the final executable
$(BUILD_DIR)/$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(OBJS) $(CFLAGS) -o $@ $(LDFLAGS)

# Compile each .cpp file to an object file
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: test clean

test: $(BUILD_DIR)/$(TARGET)
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
