#include <readline/readline.h>
#include <unistd.h> // exec and fork
#include <sys/wait.h>
#include <stdlib.h> // malloc

// gcc code.c -o code -lreadline
// Source: https://youtu.be/DdpQQOgwyy4?t=642

char** parseString(char str[]){
    // Parse input string into space separated array
    // Example: "ls -lah" -> ["ls", "-lah"]

    int i = 0;
    char** array = (char**) malloc(sizeof(char) * 50);

    array[0] = strtok(str, " ");

    // Loop is specific to strtok behaviour
    while(array[i] != NULL){
        array[++i] = strtok(NULL, " ");
    }

    return array;

}

int main(){
    int cpid;
    char *inputCommand;
    char **parsedCommand;

    while (1){

        inputCommand = readline("user@terminal $ ");
        parsedCommand = parseString(inputCommand);

        cpid = fork();
        if (cpid == 0){
            execvp(parsedCommand[0], parsedCommand);  // ls -lah
            //execv(parsedCommand[0], parsedCommand); // /bin/ls -lah
        } else{
            wait((int *)NULL);
        }
    }

    return 0;
}
