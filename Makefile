all: obj obj/FerSat.o FerSat
obj:
	mkdir -p obj/
obj/FerSat.o: src/FerSat.cpp
	g++ -c -std=c++17 src/FerSat.cpp -o obj/FerSat.o -I include
FerSat: obj/FerSat.o
	g++ obj/FerSat.o -o FerSat
clean:
	rm -rf obj/ FerSat

