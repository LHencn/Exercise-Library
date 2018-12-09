/*************************************************************************
	> File Name: hash.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年12月09日 星期日 19时28分05秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTable {
    char **m;
    int size;
}HashTable;

void init(HashTable *h, int size) {
    h->size = size;
    h->m = (char **)malloc(sizeof(char *) * h->size);
    return ;
}

int insert(HashTable *h, char value[], int *pos, int *times) {
    *pos = 0;
    *times = 0;
    while (h->m[pos] != )
}

int main() {
    return 0;
}
