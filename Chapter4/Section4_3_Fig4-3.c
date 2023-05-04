#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main()
{
    omp_set_num_threads(4);
    int size_of_team;
    #pragma omp prallel
    {
        int ID=omp_get_thread_num();
        int NThrds=omp_get_num_threads();
        if (ID==0) size_of_team=NThrds;

    }
    printf("We just did the join on a team of size \%d", size_of_team);
    system("pause");
}