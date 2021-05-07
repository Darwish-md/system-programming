#include<stdlib.h>
#include<unistd.h> 
#include<dirent.h>
#include<sys/stat.h>
#include<fcntl.h>

void print_entries(char* directory){

	DIR *folder;
	struct dirent *entry;
	chdir(directory);
	folder = opendir(".");
	
	int in, out;
	out = open("out.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IROTH);
	
	struct stat inode;
	
	while((entry=readdir(folder)) != NULL){
		stat((*entry).d_name,&inode);
		
		/*
		if we want to check if some file exists or not:
		tmp=stat(argv[1],&inode);
  		if(tmp<0){
    		fprintf(stderr," Bad name!\n");
    		return 1;
    		}
    		*/
		
		if((*entry).d_name[0] != '.' && inode.st_mode&S_IFREG && !(inode.st_mode&S_IFDIR)){
			in = open((*entry).d_name, O_RDONLY);
			char *buffer = (char*)malloc(inode.st_size);
			read(in,buffer,inode.st_size);
			write(out, buffer, inode.st_size);
			free(buffer);
		}
	}
   	
   	close(out);
   	closedir(folder);
}

int main(int argc, char* argv[]){

	if(argc == 1){
		print_entries(".");
	}
	
	if(argc == 2){
		print_entries(argv[1]);
	}
   	
   	return 0;
}