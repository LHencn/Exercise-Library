/*************************************************************************
	> File Name: 6.fork.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年05月19日 星期日 10时37分24秒
 ************************************************************************/

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;

int main(){

    int pid = fork();
    if (pid==0){
        count++;
        int pid2 = fork();
        if (pid2 == 0){
            char** argv = (char**) malloc(3*sizeof(char*));
            argv[0] = "echo";
            argv[1] = "Hello!";
            argv[2] = NULL;
            int pid3 = fork();
            count++;
            if (pid3 == 0){
                count++;
                execvp("echo", argv);
                printf("Count %d,",count);
                exit(0);
            } else {
                free(argv);
                wait(NULL);
                printf("%d,",count);
                exit(0);
            }
        } else {
            wait(NULL);
            printf("%d,",count);
            exit(0);
        }
    } else {
        wait(NULL);
        printf("%d.",count);
        return 0;
    }    
}
