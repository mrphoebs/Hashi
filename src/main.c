#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "sdbm.h"

typedef long (*hash_function)(char currenctChar, long prev_hash);

hash_function get_hash_function(char *algo){
	if(strcmp(algo, "sdbm")==0)
		return sdbm;
	else
		return NULL;	
}

int main(int argc, char** argv){
	
	char *algo, *arg;
	char c;
	long hash_output=0;
	int string_length;
	int index;

	if(argc==2||argc==3) {
		algo = argv[1];
		hash_function hash = get_hash_function(algo);

		if(hash==NULL){
			printf("Algorithm not found\n usage: hash <algo> [string|file|stdin] \n");
			return EINVAL;		
		}
		
		if(argc == 2){
			while((c = getchar())!=EOF){
				hash_output = hash(c,hash_output);
			}
			printf("%ld\n",hash_output);
			return hash_output;
		}
		else{
			arg = argv[2];
			if(access(arg,R_OK)!=EACCES||access(arg,R_OK)!=ENOENT){
				FILE *file = fopen(arg,"r");
				while((c=fgetc(file))!=EOF){
					hash_output = hash(c,hash_output);
				}
				fclose(file);
				printf("%ld\n",hash_output);
				return hash_output;
			}
			else{
				string_length = strlen(arg);
				for(index=0;index<string_length;index++){
					hash_output = hash(arg[index],hash_output);
				}
				printf("%ld\n",hash_output);
				return hash_output;	
			}	
		}
	}
	else {
		printf("Incorrect number of arguments\n usage: hash <algo> [string|file|stdin] \n");
		return EINVAL;
	}
}
