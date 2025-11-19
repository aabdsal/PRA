bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -std=c++17 -o bin/testListArray testListArray.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -std=c++17 -o bin/testListLinked testListLinked.cpp

bin/praB_Array: praB_Array.cpp ListArray.h List.h
	mkdir -p bin
	g++ -std=c++17 -o bin/praB_Array praB_Array.cpp

bin/praB_Linked: praB_Linked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -std=c++17 -o bin/praB_Linked praB_Linked.cpp

clean:
	rm -r *.o *.gch bin
