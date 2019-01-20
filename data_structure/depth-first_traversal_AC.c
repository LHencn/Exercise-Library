/*************************************************************************
	> File Name: depth-first_traversal_AC.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月20日 星期日 09时46分20秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 26
#define BEGIN_LETTER 'a'

typedef struct Node {
    int flag;
    struct Node *next[BASE];
    struct Node *fail, *father;
}Node;

Node *getNewNode(Node *father) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->father = father;
    return p;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE; i++) {
        clear(node->next[i]);
        clear(node->father);
    }
    free(node);
    return ;
}

void insert(Node *root, const char *str) {
    Node *p = root;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i]] - BEGIN_LETTER == NULL) {
            p->next[str[i] - BEGIN_LETTER] = getNewNode(p->father);
        }
        p = p->next[str[i] - BEGIN_LETTER];
    }
    p->flag = 1;
    return ;
}

void build_ac(Node *node) {
    if (node == NULL) return ;
    if (node->fail == NULL) build_ac(node->father);
    for (int i = 0; i < BASE; i++) { // 访问所有节点,将所有节点的失败指针建立
        if (node->next[i] == NULL) continue;
        Node *p = node->fail, *pre_p; //p节点有可能等于根节点
        while (p && p->next[i] == NULL) {
            if (p->fail == NULL) build_ac(p->father);
            pre_p = p;
            p = p->fail;
        }
        if (p == NULL) p = pre_p;
        else p = p->next[i];
        node->next[i]->fail = p;
        build_ac(node->next[i]);
    }
    
}


int main() {
    Node *p = getNewNode(NULL);

    return 0;
}
