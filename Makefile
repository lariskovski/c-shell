
build:
	@gcc -c src/code.c -o obj/code.o
	@gcc -c lib/hostInfo.c -o obj/hostInfo.o
	@gcc obj/code.o obj/hostInfo.o -o bin/code -lreadline
	@echo "Compiled Successfully!"

run:
	@./bin/code

clean:
	@rm -rf bin/code obj/*.o && echo "Removed 'code' file"