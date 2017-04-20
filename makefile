CC = g++ -O3
CFLAGS = -std=c++11 -Wall

NN : main.o nn.o
	$(CC) -o $@ main.o nn.o

main.o : main.cpp main.h
	$(CC) -c $(CFLAGS) main.cpp -o $@

nn.o : NN.cpp NN.h
	$(CC) -c $(CFLAGS) NN.cpp -o $@

clean:
	rm NN
	rm *.o
