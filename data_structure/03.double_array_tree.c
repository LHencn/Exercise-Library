/*************************************************************************
	> File Name: 12.double_array_tree.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月22日 星期二 19时49分32秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
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
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i < BASE_CNT; i++) {
        p->next[i] = NULL;
    }
    p->flag = 0;
    return p;
}

int insert(Node *node, const char *str) { 
    //insert返回值为在本次插入后新生成了多少个节点
    Node *p = node;
    int cnt = 1;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
            cnt += 1; 
        }
        p = p->next[str[i] - BASE];

    }
    p->flag = 1;
    return cnt;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE_CNT; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int getBase(Node *node, DATNode *trie) { 
    int base = 0, flag = 0;
    while(!flag) {
        flag = 1;
        base += 1;
        for (int i = 0; i < BASE_CNT; i++) {
            if (node->next[i] == NULL) continue;
            if (trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
    }
    return base;
}

void Transform(Node *node, DATNode *trie, int ind) {
    if (node->flag) trie[ind].check = -trie[ind].check;
    trie[ind].base = getBase(node, trie); //通过当前节点的信息和相关双数组字典树的信息
    for (int i = 0; i < BASE_CNT; i++) {
        if (node->next[i] == NULL) continue;
        trie[trie[ind].base + i].check = ind;
    }
    for (int i = 0; i < BASE_CNT; i++) {
        if (node->next[i] == NULL) continue;
        Transform(node->next[i], trie, trie[ind].base + i);
    }
    return ;
}

int search(DATNode *trie, const char *str) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        int delta = str[i] - BASE;
        int check = abs(trie[trie[p].base + delta].check);
        if (check - p) return 0;
        p = trie[p].base + delta;
    }
    return trie[p].check < 0;
}

int main() {
    Node *root = getNewNode();
    int n, cnt = 1;
    char str[100];
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    
    DATNode *trie = (DATNode *)calloc(sizeof(DATNode), cnt * 10); //双数组每个节点都有base和check值
    Transform(root, trie, 1); //最后一个参数为当前传入节点的节点编号
    while (scanf("%s", str) != EOF) {
        printf("search %s = %d\n", str, search(trie, str));
    }

    clear(root);
    return 0;
}
