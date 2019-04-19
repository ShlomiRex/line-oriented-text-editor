CXX = g++ 
CXXFLAGS = -std=c++11

FILES = Editor Document main

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

all: clean build link run
	

build: $(OBJECTS)

run: a.out
	./a.out

clean:
	rm $(BUILD_DIR)/*.o $(BUILD_DIR)/*.out -f

#Link
link: $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o bin/main.out

#Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(DBGFLAG) -I$(INCLUDE_DIR)/ -c $< -o $@