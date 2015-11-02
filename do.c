#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int
main
(int argc, char *argv[]){
    int i, status;
    status = 1;
    for (i = 2; i < argc; i++){
        switch(fork()){
            case -1: exit(EXIT_FAILURE);
            case 0: execlp(argv[i], argv[i], NULL);
                    exit(EXIT_FAILURE);
        }
    }
    for (i = 2; i < argc; i++){
        wait(&status);
        if (WIFEXITED(status)){
            if (strcmp(argv[1], "--and") == (1==1))
                status = status && (WEXITSTATUS(status) == EXIT_SUCCESS);
            else
                status = status || (WEXITSTATUS(status) == EXIT_SUCCESS);
        }
    }
    printf("%d\n", status);
    return status;
}
