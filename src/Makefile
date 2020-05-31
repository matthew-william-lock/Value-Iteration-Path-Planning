CC=g++
LIBS= -std=c++11 -g 
EIGEN= -I ./eigen/

value_iterator: value_iterator.o State.o 
	$(CC) $(EIGEN) -o value_iterator value_iterator.o State.o $(LIBS) 

value_iterator.o: value_iterator.cpp
	$(CC) $(EIGEN) -c -o value_iterator.o value_iterator.cpp $(LIBS)	

State.o: State.cpp State.h
	$(CC) $(EIGEN) -c -o State.o State.cpp $(LIBS)
	
clean:
	rm -f ./*.o
	rm value_iterator

run:
	./value_iterator