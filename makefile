CXX = g++
CXXFLAGS = -Wall



all: Loadfile.o User.o Employee.o MerkleTree.o driver.cpp
        $(CXX) $(CXXFLAGS) Loadfile.o User.o Employee.o MerkleTree.o  driver.cpp -o all

test: Loadfile.o User.o Employee.o MerkleTree.o extra_driver.cpp
        $(CXX) $(CXXFLAGS) Loadfile.o User.o Employee.o MerkleTree.o  extra_driver.cpp -o test


MerkleTree.o: User.o Employee.o MerkleTree.h MerkleTree.cpp
        $(CXX) $(CXXFLAGS) -c MerkleTree.cpp

Employee.o: User.o Employee.h Employee.cpp
        $(CXX) $(CXXFLAGS) -c Employee.cpp

User.o: User.h User.cpp
        $(CXX) $(CXXFLAGS) -c User.cpp

Loadfile.o: Loadfile.h Loadfile.cpp
        $(CXX) $(CXXFLAGS) -c Loadfile.cpp


clean:
        rm *.o*
        rm *~

run:
        ./all directory.txt

run1:
        ./test directory.txt

val:
        valgrind ./all

val1:
        valgrind ./test
