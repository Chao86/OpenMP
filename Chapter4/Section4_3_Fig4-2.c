#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
//a simple function caleed by each thread
void poch(int ID, double* A)
{
    A[ID]=ID;
}

int main()
{
    double A[10]={0};
    omp_set_num_threads(7);
    #pragma omp parallel
    {
        int ID=omp_get_thread_num();
        poch(ID, A);
        printf("A of ID(\%d)= \%1f\n", ID, A[ID]);

    }
    system("pause");

}