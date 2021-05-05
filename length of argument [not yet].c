#include<stdio.h>
#include <string.h>


int main(int argc, char* argv[]){
	if(argc == 1){
	printf("please enter an argument to execute %s", argv[0]);
}
if(argc == 2){
	/*size_t length = sizeof (argv[1]) / sizeof (*argv[1]);*/
	printf("length of argument is: %d", strlen(argv[1]));
	char a[17];
	size_t n = sizeof(a)/sizeof(a[0]);
	printf("length of argument is: %d", n); 

}


return 0;

}
