/*************************************************************************
	> File Name: 15.double_array_tree.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月24日 星期四 08时47分57秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

#define BASE_CNT 26
#define BASE 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE_CNT];
}Node;

typedef struct DATNode {
    int base, check;
}DATNode;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

void insert(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) 
            p->next[str[i] - BASE] = getNewNode();
        p = p->next[str[i] - BASE];
    }
    p->flag = 1;
    return ;
}

int search(DATNode *arr, const char *str) {
    int ind = 1;
    for (int i = 0; str[i]; i++) {
        if (abs(arr[arr[ind].base + str[i] - BASE].check) != ind) 
            return 0;
        ind = arr[ind].base + str[i] - BASE;
    }
    if (arr[ind].check < 0) 
        return 1;
    else
        return 0;
}


int getBase(Node *node, DATNode *arr) {
    int base = 1;
    int flag = 0;
    while (!flag) {
        base++;
        flag = 1;
        for (int i = 0; i < BASE_CNT; i++) {
            if (node->next[i] == NULL) continue;
            if (arr[base + i].check == 0) continue;
            flag = 0;
            break;
        }
    }
    return base;
}

int build(Node *node, DATNode *arr, int ind) {
    if (node->flag) arr[ind].check = -arr[ind].check;
    arr[ind].base = getBase(node, arr);
    for (int i = 0; i < BASE_CNT; i++) {
        if (node->next[i] == NULL) continue;
        arr[arr[ind].base + i].check = ind;
    }
    int ret = ind;
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        int temp = build(node->next[i], arr, arr[ind].base + i);
        if (temp > ret) ret = temp;
    }
    return ret;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE_CNT; i++) {
        if (node->next[i] == NULL) continue;
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int main() {
    #define MAX 50
    DATNode *dat = (DATNode *)calloc(sizeof(DATNode), 50);
    Node *root = getNewNode();
    int n;
    char str[MAX][MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
        insert(root, str[i]);
    }
    build(root, dat, 1);
    char buff[MAX];
    while (scanf("%s", buff) != EOF) {
        printf("search %s from the root is %d\n", buff, search(dat, buff));
    }

    return 0;
}
