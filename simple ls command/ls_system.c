#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 


int main(int argc, char* argv[]){

	if(argc == 1){
		system("ls");
	}
   	
   	if(argc == 2){
   		
   		chdir(argv[1]);
   		system("ls");
   	}
   	return 0;
}
