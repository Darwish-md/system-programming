#include<stdio.h>
#include <string.h>


int main(int argc, char* argv[]){
 if(argc == 1){
	fprintf(stderr, "pls enter argument");
	return 1;
}
 if(argc == 2){
	int i;
	for(i = 0; i< strlen(argv[1]); i++){
		if(argv[1][i]>= 'a' && argv[1][i]<= 'z'){
			argv[1][i] = argv[1][i] - 32;
		}
	}
	printf("The uppercase version is: %s", argv[1]);
} 
 else{
	return 1;
}
 return 0;
}
