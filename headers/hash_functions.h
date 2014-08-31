#ifndef _HASH_FUNCIONS_H_
#define _HASH_FUNCIONS_H_
#endif

typedef unsigned long (*hash_function)(char currenctChar, long prev_hash);

hash_function get_hash_function(char *algo);
