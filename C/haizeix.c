/*************************************************************************
	> File Name: haizeix.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月04日 星期四 15时55分15秒
 ************************************************************************/
//本程序为可执行文件必须为haizeix，用户名必须为lhc才可执行

#include<stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[], char **env) {
    if (app_name_valid(argc, argv) == 0) {
        fprintf(stderr, "%s\n", error_msg);
    }
    if (user_name_valid(env) == 0) {
        fprintf(stderr, "%s\n", error_msg);
    }
    printf("hello world\n");
    return 0;
}

int user_name_valid(char **env, char **perror_msg) {
    int ret = 0;
    for (char **p = env; p[0] != NULL; p++) {
        ret = ret || strcmp(p[0], "USER=lhc") == 0;
    }
    error_msg = (char *)(ret ? NULL : "wrong user-name");
    return ret;
}


