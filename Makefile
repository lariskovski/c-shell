
bin/code: obj/code.o obj/hostInfo.o
	@gcc obj/code.o obj/hostInfo.o -o bin/code -lreadline

obj/code.o: src/code.c lib/hostInfo.h
	@gcc -c src/code.c -o obj/code.o

obj/hostInfo.o: lib/hostInfo.c lib/hostInfo.h
	@gcc -c lib/hostInfo.c -o obj/hostInfo.o

run:
	@./bin/code

clean:
	@rm -rf bin/* obj/*.o && echo "Removed 'code' file"