# Makefile made by Shlomi Domnenko. I made this makefile for easy project deployment.

CXX = g++ 
CXXFLAGS = -std=c++11 -g

# Put your files names here (without extension. The .cpp and .h extension will be added automatically)
FILES = Editor Document main

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BUILD_TEST_DIR = ${BUILD_DIR}/test
TEST_DIR = test

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

all: clean build link run

build: $(OBJECTS)

#Run main program
run: $(BUILD_DIR)/a.out
	./$(BUILD_DIR)/a.out

#Clean build objects
clean:
	@find ${BUILD_DIR} \( -name "*.o" -o -name "*.out" \) -type f -delete
	@rm tmp.txt -f
#Does not remove files recursivly, only dirs
#So we use 'find' instead
#rm $(BUILD_DIR)/*.o $(BUILD_DIR)/*.out -f
#rm $(BUILD_DIR)/test/*.o $(BUILD_DIR)/test/*.out -f
	
#Link
link: $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $(BUILD_DIR)/a.out

#Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(DBGFLAG) -I$(INCLUDE_DIR)/ -c $< -o $@


#Test program 'test.cpp'. NOT main tests.
mytest:
	#Compile
	$(CXX) $(CXXFLAGS) $(DBGFLAG) -c $(SRC_DIR)/test/test.cpp -o $(BUILD_TEST_DIR)/test.o 
	#Link
	$(CXX) $(LDFLAGS) $(BUILD_TEST_DIR)/test.o -o $(BUILD_TEST_DIR)/test.out
	#Run
	./$(BUILD_TEST_DIR)/test.out

run_tests: clean build link test1 test2 test3 test4 test_main

test%:
	@echo Running $@...
	./$(BUILD_DIR)/a.out < $(TEST_DIR)/$@_input.txt > tmp.txt
	diff $(TEST_DIR)/$@_output.txt tmp.txt
	@echo Success\n

prepare_files_for_submission:
	rm -f 318643640.zip
	zip 318643640.zip src/Document.cpp src/Editor.cpp $(HEADERS) -j