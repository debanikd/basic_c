#!/bin/bash
#SBATCH -N 1
###SBATCH --ntasks-per-node=4
###SBATCH --ntasks=1
#SBATCH -n 1
#SBATCH -t 21:00:00
#SBATCH --mem=128G
###SBATCH -p long
#SBATCH --job-name=basic_c
#SBATCH --output=info_%j.log
#SBATCH --error=error_%j.log

module load slurm
module load gmp
#module load mumps/gcc-4.8.5/5.1.1
module load lapack/gcc/64/3.7.0
#module load mvapich2/gcc/64/2.2rc1
#module load mpich/gcc-4.8.5/3.1.3
module list

#mpiexec -np 1 --hostfile hostlist.txt ./a.out FEMstruct.inp materialParams.inp
./a.out #-eps_target 0.00 -eps_target_magnitude -memory_view -malloc_log #-st_ksp_type preonly -st_pc_type lu -st_pc_factor_mat_solver_type mumps 
 
