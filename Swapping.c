#include<stdio.h>
#include <stdlib.h> 

void swap(float *a, float *b){
    *a = *a - *b;   
 
    *b = *a + *b;

    *a = *b - *a;
    
    return;
}

int main(int argc, char* argv[]){
   if(argc <= 2){
   	printf("pls provide two arguments");
   }
   
   if(argc == 3){
   	float a = strtof(argv[1], NULL);
   	
   	float b = strtof(argv[2], NULL);

        /* for integer values:
        int a = strtol(argv[1], NULL, 0);
   	    int b = strtol(argv[2], NULL, 0); */

   	
   	printf("a equals %f & b equals %f\n", a, b);
   	
   	swap(&a, &b);
   	
   	printf("a equals %f & b equals %f\n", a, b);
   }

   return 0;
}
