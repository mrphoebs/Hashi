#include "hash_functions.h"
#include "sdbm.h"
#include <string.h>

hash_function get_hash_function(char *algo){
	if(strcmp(algo, "sdbm")==0)
		return sdbm;
	else
		return NULL;	
}
