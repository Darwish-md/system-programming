#include <stdio.h>
int main()  
{  
    int arr[25], i, *smallest;  
  
    printf("Enter 25 integer numbers\n");  
    
    for(i = 0; i < 25; i++)  
        scanf("%d", &arr[i]);  
  
    smallest = &arr[0];  
  
    for(i = 1; i < 25; i++)  
    {  
        if( *(arr + i) < *smallest)  
            *smallest = *(arr + i);  
    }  
  
    printf("Smallest number in the array is : %d\n", *smallest);  
  
    return 0;  
} 
