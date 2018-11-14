#PBS -N test_scheduler
#PBS -l nodes=4:ppn=4
#PBS -M ja.saavedra10@uniandes.edu.co
#PBS -m abe

module load rocks-openmpi_ib
module load anaconda/python3
cd ja.saavedra
mpiexec -v -np 4 ./sample.cpp 500 0 1
