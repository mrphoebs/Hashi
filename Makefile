bin/hash: src/sdbm.c src/main.c headers/sdbm.h
	gcc -Wall src/main.c src/sdbm.c -Iheaders -o bin/hash
