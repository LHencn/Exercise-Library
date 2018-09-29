/*************************************************************************
	> File Name: pra.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月13日 星期四 18时29分31秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
int main(void) {
    FILE *FSPOINTER;
    char STRBUFF[16] = "23";
    //...
    FSPOINTER = fopen("HELLO.TXT", "w+");
    //...
    string m = fprintf(FSPOINTER, "%s", STRBUFF);
    printf("%s", m);
    printf("%%");
    //...
    return 0;
}
