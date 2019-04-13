/*************************************************************************
	> File Name: 10.hashTable.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月08日 星期一 10时00分08秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    char *str;
    struct Node *next;
}Node;

typedef struct HashTable {
    Node **data;
    int size;
}HashTable; 

Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    h->data = (Node **)malloc(sizeof(Node *) * h->size);
}



int main() {






    return 0;
}
