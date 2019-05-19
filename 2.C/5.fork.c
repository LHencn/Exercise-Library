/*************************************************************************
	> File Name: 5.fork.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年05月18日 星期六 20时29分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("%s\n", "我是鸣人！");
    /*YOUR CODE HERE*/
    int pid = fork();
    int status1, status2;
    if (pid != 0) {
        wait(&status1);
        if (status1 != 0) {
            printf("可恶，又失败了，再来一次！\n");
            return -1;
        } 
        printf("我负责性质变化！\n");
    } else {
        int pid = fork();
        if (pid != 0) {
            wait(&status2);
            if (status2 != 0) {
                printf("可恶，又失败了，再来一次！\n");
                return -1;
            }
            printf("我负责形态变化！\n");
            exit(0);
        } else {
            printf("我负责产生查克拉！\n");
            exit(0);
        }
    }
    
    return 0;
}
