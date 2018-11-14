#PBS -l nodes=1:ppn=1,mem=2gb,walltime=00:10:00
#PBS -M ja.saavedra@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio26


module load anaconda/python3
cd ja.saavdra # este es el directorio desde donde se ejecuto qsub
make -f mkf.mk

