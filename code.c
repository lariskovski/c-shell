#include <readline/readline.h>
#include <unistd.h> // exec and fork
#include <sys/wait.h>
#include <stdlib.h> // malloc
#include <pwd.h> // getpwuid


const char *getUserName()
{
  uid_t uid = geteuid();
  struct passwd *pw = getpwuid(uid);
  if (pw)
  {
    return pw->pw_name;
  }

  return "";
}


char** parseString(char str[]){
    /* Parse input string into space separated array
    Example: "ls -lah" -> ["ls", "-lah"] */

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
    char *inputCommand;
    char **parsedCommand;

    const char *username = getUserName();

    char shellPrompt[50]; 
    strcpy(shellPrompt, username);
    strcat(shellPrompt, "@terminal $ ");

    while (1){

        inputCommand = readline(shellPrompt);
        parsedCommand = parseString(inputCommand);

        cpid = fork();
        if (cpid == 0){
            execvp(parsedCommand[0], parsedCommand);  // ls -lah
            //execv(parsedCommand[0], parsedCommand); // /bin/ls -lah
        } else{
            free(parsedCommand);
            wait((int *)NULL);
        }
    }

    return 0;
}
