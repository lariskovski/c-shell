
build: code.c hostInfo.c
	@gcc -c code.c -o code.o
	@gcc -c hostInfo.c -o hostInfo.o
	@gcc code.o hostInfo.o -o code -lreadline
	@echo "Compiled Successfully!"

run: code
	@ ./code

clean:
	@rm -rf code *o && echo "Removed 'code' file"