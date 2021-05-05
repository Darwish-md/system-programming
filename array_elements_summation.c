#include<stdio.h>
#include <stdlib.h> 

//could be written as float sum(float T[], int size_of_array)
float sum(float *T, int size_of_array){ 
   int i;
   float s=0;
   for(i=0;i<size_of_array;i++)
   	s+=T[i];
   return s;
}

int main(int argc, char* argv[]){
   float sum1,sum2;
   float A[8]={1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9};
   sum1 = sum(A,8); // sum of elements from A[0] to A[7]
   sum2 = sum(&A[2],3); // sum of elements from A[2] to A[4]
   printf("sum1 is: %f\n", sum1);
   printf("sum2 is: %f\n", sum2);
   return 0;
}