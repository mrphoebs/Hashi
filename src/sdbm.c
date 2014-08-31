
long sdbm(unsigned char *str, int length){
	long hash = 0;
	int index;

	for(index=0; index<length; index++)
		hash = (hash<<2) + (hash<<6)-hash + str[index];

	return hash;
}
