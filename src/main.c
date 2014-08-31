#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "sdbm.h"

int main(int argc, char** argv){
	
	char *algo, *str;

	if(argc!=3){
		printf("Incorrect number of arguments\n hash <algo> <string>");
		return EINVAL;
	}

	algo = argv[1];
	str = argv[2];

	if(strcmp(algo,"sdbm")==0){
		printf("%ld\n",sdbm(str,strlen(str)));
	}
	return 0;
}
