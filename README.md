# C Shell

Very simple C Shell project to exercise the following C Topics:

- Functions, Scopes
- Pointers
- Pass by value, Pass by pointer
- Arrays, Strings
- String Manipulation
- C Compile Process
- Makefiles, Targets, Dependencies
- Heap, Malloc, Free
- Fork, Exec

## Requirements

- Basic Linux knowledge
- GCC

## Usage

~~~~
make
./bin/shell
# Exit it with Ctrl + C 
make clean
~~~~

## Possible Errors

### GCC Not Present

~~~~~
sh-4.2$ make
/bin/bash: gcc: command not found
~~~~~

Fix command:

``sudo yum install gcc -y``


### readline Not Present

~~~~
src/main.c:1:10: fatal error: readline/readline.h: No such file or directory
 #include <readline/readline.h>
~~~~

Fix  command:

``sudo yum install readline-devel -y``


## Sources

[ECE141 - Programming for Engineers](https://www.youtube.com/playlist?list=PL-ftFcielQtFNIa_X4kzvV_qlgujHqAek)

[Exec Explained](https://www.youtube.com/watch?v=DdpQQOgwyy4)

[Fork Explained](https://www.youtube.com/watch?v=hKA3wJtyDo4)

[How to get the username in C/C++ in Linux?](https://stackoverflow.com/a/8953445)

[Makefiles](https://www.youtube.com/watch?v=W-QgOChAnAQ)

[The C Compiler](https://www.youtube.com/watch?v=9a-d_scGeDI)