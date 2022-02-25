#include <stdlib.h>
#include <readline/readline.h>

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
