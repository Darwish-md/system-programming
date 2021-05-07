/*
Write a C program, which continuously prints out integer numbers in increasing order started by 1. 
The program must terminate after 1 second. To implement the program use a timer and signaling.
*/
#include<stdio.h>
#include <stdlib.h> 
#include<unistd.h>
#include<signal.h>

void end(int sig){
   fprintf(stderr,"\n Sorry, time out!\n");
   kill(getpid(),SIGKILL);
  }

int main(int argc, char* argv[]){
	signal(SIGALRM,end);
        alarm(1);
	int i=1;
	while(1){
		printf("%d\n", i);
		i++;
	}
	
   	return 0;
}

//-------------------------------------
/*
There is a file containing integer numbers (each integer is followed by a newline character). 
The number of integers is unknown. The file is called “nums.txt”. Write a C program to calculate the sum of the integers and write it to the end of the file.
*/
#include <stdio.h>

void main(){
  int sum =0;
  FILE *f;
  int data;
  f= fopen("nums.txt","r+");
  if(f == NULL){
    printf("The file doesn't exist");
  }else{

    while(!feof(f)){
      fscanf(f,"%d\n", &data);
      sum+=data;
    }

  }


 fprintf(f, "%d\n",sum);

fclose(f);

}

//-------------------------------------
/*
Write a C program, in which you define a function without any parameter. 
The function randomly returns an English letter character. The probability of the lowercase letters must be the double than the probability of uppercase letters.
(The character should not be the same for each run.) Call the function in the main program unit and print the returned value. (Hint: ‘a’ is 97 and ‘A’ is 65.)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void random_letter(){
	
	srand(time(NULL));

	char letter;
	
	double probability = (double)rand()/RAND_MAX;

	if (probability<=1.0/3){
     		letter = rand()%('Z' - 'A' + 1) + 'A' ;
     		printf("%c\n",letter);
	}
	if(probability>1.0/3) {
    		letter = rand()%('z' - 'a' + 1) + 'a'; 
    		printf("%c\n",letter);
	}
}

int main(int argc, char argv[]){
	random_letter();
	return 0;
}

//-------------------------------------
/*
Write a C program, in which you define a procedure having 4 parameters. The first two parameters are integers, the first one plays the role of the dividend (numerator)
and the second one is the divisor (dominator) of a division. The procedure must determine both the integer part of the quotient and reminder and they must be provided to
the caller via parameter passing by pseudo-address using the third and fourth parameters as output parameters. Call the procedure using the 60 and 8 as input parameters 
and in the main program unit print out the results (7 and 4).
*/
#include<stdio.h>
#include <stdlib.h> 


void function(int x, int y, int *a, int *b){ 
    *a = x/y;
    *b = x%y;
    return;
}

int main(int argc, char* argv[]){
	int a,b;
	function(60, 8, &a, &b);
	printf("The quotient is %d and the remainder is %d\n", a, b);
   	return 0;
}

//-------------------------------------
