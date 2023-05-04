#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

#define NTHREADS 2
// #define NUMSTEPS 100000000
static long num_steps=1000000000;
double step;

int main()
{
    int i,actual_nthreads;
    double pi, start_time, run_time;
    // double sum[NUMSTEPS]={0.0};
    double sum[NTHREADS]={0.0};
    step=1.0/(double) num_steps;
    omp_set_num_threads(NTHREADS);
    start_time=omp_get_wtime();
    #pragma omp parallel
    {
        int i;
        int id=omp_get_thread_num();
        int numthreads=omp_get_num_threads();
        double x;
        
        if(id==0) actual_nthreads=numthreads;

        int istart=id*num_steps/numthreads;
        int iend= (id+1)*num_steps/numthreads;

        if(id==(numthreads-1)) iend=num_steps;

        for(i=istart; i<iend; i++)
        {
            x=(i+0.5)*step;
            sum[id]+=4.0/(1.0+x*x);
        }
    } //end of parallel region
     pi=0.0;
    for(i=0; i<actual_nthreads; i++)
    {
        pi+=sum[i];
    }
    pi=step*pi;
    run_time=omp_get_wtime()-start_time;
    printf("\n pi is \%f in \%f secongs \%d thrds \n", pi, run_time, actual_nthreads);
    system("pause");
}