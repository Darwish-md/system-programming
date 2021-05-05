#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char* argv[]){
  time_t t;
  time(&t);
  printf("The current program name: %s \n", argv[0]);
  printf("The current working directory: %s \n", getenv("PWD"));
  printf("the current user: %s \n", getenv("LOGNAME"));
  printf("The current date & time: %s", ctime(&t));
  return 0;
   }
