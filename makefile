a8: graph.o main.cpp
	g++ -o a8.out main.cpp graph.o

main.o: graph.o main.cpp
	g++ -o a8.out main.cpp graph.o

graph.o: graph.h graph.cpp
	g++ -c -o graph.o graph.cpp

clean: 
	rm *.o