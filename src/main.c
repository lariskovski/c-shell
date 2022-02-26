#include <stdio.h> // Needed for proper readline include on centos
#include <readline/readline.h>
#include <sys/wait.h>
#include <unistd.h>     // exec and fork
#include <stdlib.h>     // malloc free

#include "../lib/hostInfo.h"
#include "../lib/strings.h"


int main(){
    int cpid;
    char* inputCommand;
    char** parsedCommand;

    char* username = getUserName();
    char* hostname = getHostname();

    char shellPrompt[50]; 
    strcpy(shellPrompt, username);
    strcat(shellPrompt, "@");
    strcat(shellPrompt, hostname);
    strcat(shellPrompt, " $ ");

    while (1){
        inputCommand = readline(shellPrompt);
        parsedCommand = splitStringBySpace(inputCommand);

        cpid = fork();
        if (cpid == 0){
            execvp(parsedCommand[0], parsedCommand); 
        } else{
            free(parsedCommand);
            wait((int *)NULL);
        }
    }

    return 0;
}
