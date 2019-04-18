CXX = g++ 
CXXFLAGS = -std=c++11

all: clean build link run
	

build: Editor.o Document.o main.o

run: a.out
	./a.out

clean:
	rm *.o -f

link: Editor.o Document.o main.o
	$(CXX) $^ -o a.out

Editor.o:
	$(CXX) $(CXXFLAGS) -c Editor.cpp
Document.o:
	$(CXX) $(CXXFLAGS) -c Document.cpp
main.o:
	$(CXX) $(CXXFLAGS) -c main.cpp
