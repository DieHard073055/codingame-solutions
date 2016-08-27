all: CM

CM: Cadet_Manager.o Cadet.o
	g++ Cadet_Manager.o Cadet.o -o CM

Cadet_Manager.o: Cadet_Manager.cpp
	g++ -c Cadet_Manager.cpp

Cadet.o: Cadet.cpp
	g++ -c Cadet.cpp

clean:
	rm -rf *.o CM
