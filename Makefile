SHELL=/bin/bash

bin/shell: obj/main.o obj/hostInfo.o obj/strings.o
	@gcc obj/main.o obj/hostInfo.o obj/strings.o -o bin/shell -lreadline

obj/main.o: src/main.c lib/hostInfo.h
	@mkdir {obj,bin}
	@gcc -c src/main.c -o obj/main.o

obj/hostInfo.o: lib/hostInfo.c lib/hostInfo.h
	@gcc -c lib/hostInfo.c -o obj/hostInfo.o

obj/strings.o: lib/strings.c lib/strings.h
	@gcc -c lib/strings.c -o obj/strings.o

run:
	@./bin/main

clean:
	@rm -rf bin/ obj/ && echo "Removed files"