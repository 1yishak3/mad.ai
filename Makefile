INC=-I/usr/local/cuda/include
NVCC=/usr/local/cuda/bin/nvcc
NVCC_OPT=-std=c++11

Perceptron: Perceptron.o

Perceptron.o: Perceptron.h Perceptron.cpp

all: Perceptron.o Perceptron.cpp
	$(NVCC) $(NVCC_OPT) Perceptron.h Perceptron.cpp -o Perceptron

clean:
	rm -f Perceptron
