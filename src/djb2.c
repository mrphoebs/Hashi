#include <stdlib.h>

unsigned long djb2(char c, long prev_hash_val){
	return abs(prev_hash_val*33^c);
}
