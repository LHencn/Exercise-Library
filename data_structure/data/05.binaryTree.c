/*************************************************************************
	> File Name: 05.binaryTree.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年02月12日 星期二 07时37分11秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
}Node, *Tree;

Tree init(int val) {
    Node *t = (Node *)malloc(sizeof(Node));
    t->data = val;
    t->lchild = t->rchild = NULL;
    return t;
}

Node *insert(Node *t, int val) {
    if (t == NULL) {
        t = init(val);
        return t;
    } else if (val == t->data) {
        return t;
    } else if (val > t->data) {
        t->rchild = insert(t->rchild, val);
    } else if (val < t->data) {
        t->lchild = insert(t->lchild, val);
    } 
    return t;
}

int search(Node *t, int val) {
    if (t == NULL) {
        return 0;
    } else if (val == t->data) {
        return 1;
    } else if (val > t->data) {
        return search(t->rchild, val);
    } else if (val < t->data) {
        return search(t->lchild, val);
    } 
    return 0;
}

void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
}

void output(Node *node) {
    if (node == NULL) return ;
    output(node->lchild);
    printf("%d ", node->data);
    output(node->rchild);
    return ;
}

int main() {
    srand(time(0));
    Tree t = init(0);
    for (int i = 0; i < 10; i++) {
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                int val = rand() % 100;
                insert(t, val);
                printf("insert : %d\n", val);
                output(t);
                printf("\n");
                break;
            }
            case 3: {
                int val = rand() % 100;
                printf("search %d from t is %d\n", val, search(t, val));
                output(t);
                printf("\n");
                break;
            }
        }
    }
    clear(t);
    return 0;
}

