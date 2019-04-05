/*************************************************************************
	> File Name: m.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月05日 星期五 08时18分05秒
 ************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[], char **env) {
    int i = 0;
    while (argc--) {
        printf("%s\n", argv[i]);
        i++;
    }
    printf("%s\n", env[0]);
    return 0;
}
