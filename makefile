#EXECS=mpi_hello_world
#MPICC?=mpicc

sample: mpi_hello_world.c
	mpic++ -o sample sample.cpp
	./sample 500 0 1

