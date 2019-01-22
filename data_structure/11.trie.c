/*************************************************************************
	> File Name: 11.trie.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月22日 星期二 18时34分52秒
 ************************************************************************/
/*
 * 字典树
 */
#include<stdio.h>
#include <stdlib.h>
#define BASE_CNT 26
#define BASE 'a'

typedef struct Node{
    int flag;
    struct Node *next[BASE_CNT];
} Node;

Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < BASE_CNT; i++) {
        p->next[i] = NULL;
        p->flag = 0;
    }
    return p;
}

void insert(Node *node, const char *str) {
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
        }
        p = p->next[str[i] - BASE];
    }
    p->flag = 1;
    return ;
}

int search(Node *node, const char *str) {
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            return 0;
        }
        p = p->next[str[i] - BASE];
    }
    return p->flag;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE_CNT; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int main() {
    Node *root = getNewNode();
    char str[100];
    int op;
    while (scanf("%d%s", &op, str) != EOF) {
        switch(op) {
            case 0: {
                printf("%s insert the root\n", str);
                insert(root, str);
                break;
            }
            case 1: {
                printf("search %s from the root is %d\n", str, search(root, str));
                break;
            }
        }
    }

    return 0;
}
