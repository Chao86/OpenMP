#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

static long num_steps=1000000000;
double step;

int main()
{
    int i;
    double x,pi ,sum=0.0;
    double start_time, run_time;

    step=1.0/(double) num_steps;
    start_time=omp_get_wtime();

    for(i=0; i<num_steps; i++)
    {
        x=(i+0.5)*step;
        sum+=4.0/(1.0+x*x);
    }
    pi=step*sum;
    run_time=omp_get_wtime()-start_time;
    printf("pi= \%1f, \%1d steps \%1f , \%1f secs \n", pi, num_steps, run_time);
    system("pause");

}