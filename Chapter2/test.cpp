#include<iostream>
#include<stdlib.h>
#include<omp.h>
#include<cmath>
int main()
{
    #pragma omp parallel
    {
        std::cout<<"Hello "<<std::endl;
        std::cout<<" World! \n"<<std::endl;
    }
    
    system("pause");
    //return 1;
}