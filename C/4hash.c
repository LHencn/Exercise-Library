/*************************************************************************
	> File Name: 4hash.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年12月10日 星期一 17时50分10秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    struct Node *next;
}Node;

typedef struct HashTable {
    Node **data;
    int size;
}HashTable;

HashTable *init_hashtable(int size) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = 2 * size;
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    /*for (int i = 0; i < h->size; i++) {
        h->data[i]->str = NULL;
        h->data[i]->next = NULL;
    }*/
    return h;
}

Node *init_node(char *str, Node *node) {
    Node *head = node, *p;
    p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

int BKDRhash(char *str) {
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) {
        hash = hash * seed + str[i];
    }
    return hash;
}
void insert(HashTable *h, char *str) {
    int hash = BKDRhash(str);
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    return ;
}

int search(HashTable *h, char *str) {
    int hash = BKDRhash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while (p) {
        if (strcmp(p->str, str) == 0) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}
void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
        if (h->data[i] != NULL) {
            clear_node(h->data[i]);
        }
    }
    free(h->data);
    free(h);
    return ;
}


int main() {
    int op;
    HashTable *hashtable = init_hashtable(100);
    char *str;
    while (scanf("%d%s", &op, str) != EOF) {
        switch(op) {
            case 0: {
                insert(hashtable, str);
                printf("success %s to hashtable\n", str);
            } break;
            case 1: {
                printf("search result = %d\n", search(hashtable, str));
            }
        }
    }
    return 0;
}
