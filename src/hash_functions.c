#include "hash_functions.h"
#include "sdbm.h"
#include "djb2.h"
#include <string.h>

hash_function get_hash_function(char *algo){
	if(strcmp(algo, "sdbm")==0)
		return sdbm;
	else if(strcmp(algo,"djb2")==0)
		return djb2;
	else
		return NULL;	
}
