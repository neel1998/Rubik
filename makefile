Rubik: rubik.o move.o cross.o first_layer.o second_layer.o third_layer.o
	 g++ -o Rubik rubik.o move.o cross.o first_layer.o second_layer.o third_layer.o
clean:
	@rm -f *.o Rubik
rubik.o: rubik.cpp
	g++ -c rubik.cpp
move.o: move.cpp
	g++ -c move.cpp
cross.o: cross.cpp
	g++ -c cross.cpp
first_layer.o: first_layer.cpp
	g++ -c first_layer.cpp
second_layer.o: second_layer.cpp
	g++ -c second_layer.cpp
third_layer.o: third_layer.cpp
	g++ -c third_layer.cpp