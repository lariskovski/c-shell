#include <readline/readline.h>
#include <sys/wait.h>
#include <unistd.h>     // exec and fork
#include <stdlib.h>     // malloc
#include <limits.h>     // HOST_NAME_MAX
#include <pwd.h>        // getpwuid


char* getUserName(){
  uid_t uid = geteuid();
  struct passwd* pw = getpwuid(uid);
  if (pw){
    return pw->pw_name;
  }
  return "";
}


char* getHostname(){
    char* hostname =  (char*) malloc(sizeof(char) * HOST_NAME_MAX + 1);
    gethostname(hostname, HOST_NAME_MAX + 1);
    return hostname;
}


char** splitStringBySpace(char str[]){
    int i = 0;
    char** array = (char**) malloc(sizeof(char) * 50);
    // malloc returns NULL when failed to allocate memory
    if (array != NULL){ 
        array[0] = strtok(str, " ");
        // Specific to strtok behaviour
        while(array[i] != NULL){
            array[++i] = strtok(NULL, " ");
        }
    }
    return array;
}


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
