CXX = g++ 
CXXFLAGS = -std=c++11 -g

FILES = Editor Document main

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

all: clean build link run_test

run_test: clean build link
	$(BUILD_DIR)/a.out < TEST

build: $(OBJECTS)

run: $(BUILD_DIR)/a.out
	./$(BUILD_DIR)/a.out

clean:
	rm $(BUILD_DIR)/*.o $(BUILD_DIR)/*.out -f
	rm $(BUILD_DIR)/test/*.o $(BUILD_DIR)/test/*.out -f
	
	

test: 
	#Compile
	$(CXX) $(CXXFLAGS) $(DBGFLAG) -c $(SRC_DIR)/test/test.cpp -o $(BUILD_DIR)/test/test.o 
	#Link
	$(CXX) $(LDFLAGS) $(BUILD_DIR)/test/test.o -o $(BUILD_DIR)/test/test.out
	#Run
	./$(BUILD_DIR)/test/test.out

#Link
link: $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $(BUILD_DIR)/a.out

#Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(DBGFLAG) -I$(INCLUDE_DIR)/ -c $< -o $@