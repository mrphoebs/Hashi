bin/hash: src/*.c headers/*.h
	gcc -Wall src/*.c -Iheaders -o bin/hash
