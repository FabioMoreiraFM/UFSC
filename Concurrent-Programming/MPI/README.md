#MPI

For both:

To compile:

mpicc findPi.c -o name_exe -std=c99

To run:

mpirun -np number_processes ./name_exe number_of_points
