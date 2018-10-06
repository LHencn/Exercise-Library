/*************************************************************************
	> File Name: haizeix_lhc.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月06日 星期六 14时38分25秒
 ************************************************************************/
//该文件的可执行文件名必须为haizeix，执行的用户名必须为lhc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *error_msg = NULL;
int app_name_valid(char *argv[]);
int user_name_valid(char **);

int main(int argc, char *argv[], char *env[]) {
    if (app_name_valid(argv) == 0) {
        fprintf(stderr, "%s\n", error_msg);
        return 0;
    }
    if (user_name_valid(env) == 0) {
        fprintf(stderr, "%s\n", error_msg);
        return 0;
    }
    printf("Hello HaiZei\n");
    return 0;
}

int app_name_valid(char *argv[]) {
    int i = strlen(argv[0]);
    while (i > 0 && argv[0][i - 1] != '/') --i;
    int ret = (strcmp(argv[0] + i, "haizeix") == 0);
    error_msg = (char *)(ret ? NULL : "wrong app-name");
    return ret;
}

int user_name_valid(char **env) {
    int ret = 0;
    for (char **p = env; p[0] != NULL; p++) {
        ret = ret || strcmp(p[0], "USER=lhc") == 0;
    }
    error_msg = (char *)(ret ? NULL : "wrong user-name");
    return ret;
}

