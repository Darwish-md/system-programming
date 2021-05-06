#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 
#include<dirent.h>

void list_entries(const char* directory){
	DIR *folder;
   	struct dirent *entry;
   	folder = opendir(directory);
  	while((entry=readdir(folder)) != NULL){
   		if((*entry).d_name[0] != '.'){
   			printf("%s\t", (*entry).d_name);
   		}
   	}
   	
   	closedir(folder);
}

int main(int argc, char* argv[]){

	if(argc == 1){
		list_entries(".");
	}
   	
   	if(argc == 2){
		list_entries(argv[1]);
   	}
   	return 0;
}
