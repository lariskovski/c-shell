
bin/code: obj/code.o obj/hostInfo.o obj/strings.o
	@gcc obj/code.o obj/hostInfo.o obj/strings.o -o bin/code -lreadline

obj/code.o: src/code.c lib/hostInfo.h
	@gcc -c src/code.c -o obj/code.o

obj/hostInfo.o: lib/hostInfo.c lib/hostInfo.h
	@gcc -c lib/hostInfo.c -o obj/hostInfo.o

obj/strings.o: lib/strings.c lib/strings.h
	@gcc -c lib/strings.c -o obj/strings.o

run:
	@./bin/code

clean:
	@rm -rf bin/* obj/*.o && echo "Removed files"