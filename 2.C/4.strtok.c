/*************************************************************************
	> File Name: 4.strtok.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年05月17日 星期五 20时37分13秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 256;

char* get_letter(void) {
    static char letter[1000000];
    letter[999999] = ' ';
    char *p = letter;
    int size = MAX_LENGTH;
    while (feof(stdin) == 0) {
        if (size == 0) {
            break;
        }
        fgets(p, size + 1, stdin);
        while (*p != '\0') {
            p++;
            size--;
        }
    }
    return letter;
}

int main() {
    char *str = get_letter();
    char *pase = malloc(sizeof(char) * MAX_LENGTH);
    pase = strcpy(pase, str);
    
    // 在此处添加你的代码
    char dest[] = {' ', '\t', '\n', '\"', '\r\n', '\'', ',', '.', '\0'};
    char *p = strtok(pase, dest);
    while (p = strtok(NULL, dest)) {
        printf("%s\n", p);
    };
    printf("%s", str);
    puts(str);
    
    return 0;
}

#undef MAX_LENGTH

