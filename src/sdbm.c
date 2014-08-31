
/**
 * One is supposed to call this hash function in a loop where
 * each time a new character from the source is fed into the 
 * hash computation, along with the output of the previous
 * iteration's hash computation. This enables us to use streams
 * from different origins to comput hashes
 */

long sdbm(char c, long prev_hash_val){
	return (prev_hash_val<<6) + (prev_hash_val<<16)-prev_hash_val + c;
}
