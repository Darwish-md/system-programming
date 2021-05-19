/*
Write a C program, which dynamically allocates a memory field for 100 integers. Then ask an integer from the user. 
Modify the size of the allocated field to be enough for the number of integers specified as input, so extend or shrink the original allocation. 
Fill the total array with integers in increasing order started by 1. After that, cancel the effect of allocation manually.
*/

#include<stdlib.h>
#include<unistd.h> 
#include<stdio.h> 

int main(){
 int *arr = (int*)malloc(100*sizeof(int));
 int a,i;
  
 printf("Pls enter an integer: ");
 scanf("%d", &a);

 arr = (int*)realloc(arr,a*sizeof(int));

 for(i = 0; i<a;){

   arr[i] = ++i;
   printf("%d\n", arr[i]);
 }
	
	free(arr);
  return 0;
}


-------------------------------------
/*
There is a binary file containing 10 integer numbers (as the same byte sequence as it can be in the RAM). 
The file is called “nums.txt”. Write a C program to calculate the sum of the integers using low-level file management and write it to the screen.
*/

#include<stdio.h>
#include <sys/stat.h> 
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char argv[]){

	int arr[10];
	int i, sum = 0;

	/*
	for(i=0;i<10;i++){
	     	 arr[i] = i;
	}
	int f = open("nums.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IROTH); 
        write(f,arr,10*sizeof(int)); 
        close(f); 
   	*/

   	f = open("nums.txt",O_RDONLY);
  	 int n = read(f,arr,10*sizeof(int)); //returns number of bytes read from file.
  
   	for(i=0;i<10;i++){
     		printf("%d\n", arr[i]);
     		sum += arr[i]; 
   	}

	printf("The sum equals: %d\n", sum);			
    	close(f); 
	return 0;

}

--------------------------------------

/*Write a C program, which gets a command-line argument in each run. 
The program must tell whether the first word of the command line arguments (excluding the name of the executable) is a regular file name or a directory name (or none) 
in the present working directory. So, it prints out either a “File”, a “Directory” or a “None” world. 
If the current directory contains only two objects besides the “a.out” executable file, a file called “task.c” and a directory called “Progs”, 
then the following executions are expected:

> ./a.out  Progs
Directory
> ./a.out  task.c
File
> ./a.out  Progs.c
None
*/
  
#include<stdlib.h>
#include<unistd.h> 
#include<stdio.h> 
#include<sys/stat.h>

void check_entity(char* entity){

	struct stat inode;	
	int tmp=stat(entity,&inode);
  
  	if(tmp<0){
      fprintf(stderr," entity doesn't exist!\n");
    }

   	if(inode.st_mode&S_IFDIR)   				
		  printf("Directory.\n");

  	if(inode.st_mode&S_IFREG)
		  printf("File.\n");

 		else 
      printf("None.\n");
}


int main(int argc, char* argv[]){

	if(argc == 1){
		printf("Pls enter an argument");
	}

	if(argc == 2){
    check_entity(argv[1]);
	}

  return 0;
}


------------------------------
/*Write a C program, which prints out the current system time in a readable form if the program receives an interrupt signal (ctrl+c). 
While the program waits for the signal it does not need to do anything.
*/

#include<stdlib.h>
#include<unistd.h> 
#include<stdio.h> 
#include<signal.h>
#include<time.h>

void show_time(){
	time_t t; 
	time(&t);
	char* readable_format = ctime(&t);
	printf("\nTime & date: %s", readable_format);
}


int main(int argc, char* argv[]){
	signal(SIGINT, show_time);
	pause();
  return 0;
}

---------------------------------
/*Write a C program, in which you define a function having only one unsigned integer parameter. 
The function swaps the two halves of the parameter by bit operations and returns by this value. 
So the most significant 2 bytes of the parameter must be the least significant 16 bits of the result and the least significant half of the 4-byte long parameter 
must be the most significant 16 bits of the return value. (The order of bits within the half integers does not change.) 
Call this function passing a value given by the user.

For example:
parameter in decimal: 3923
parameter in binary: 0001111 01010011
return value in binary: 01010011 00001111
return value in decimal: 21263
*/
  
#include<stdlib.h>
#include<unistd.h> 
#include<stdio.h> 

unsigned int swap(unsigned int *N){

	unsigned int first_half = (*N<<16);
	//printf("%u\n", first_half);
	unsigned int second_half = (*N>>16);
	//printf("%u\n", second_half);
	 *N = first_half | second_half;
	 return *N;
}

int main(){
	unsigned int N;
	printf("Enter a number to swap: ");
	scanf("%u", &N);
	swap(&N);
	printf("After swapping: %u\n", N);
	return 0;
}
