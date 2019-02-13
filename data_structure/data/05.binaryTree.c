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

Node *predecessor(Node *node) {
    Node *temp = node->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *node, int key) {
    if (node == NULL) return node;
    if (key > node->data) {
        node->rchild = erase(node->rchild, key);
    } else if (key < node->data) {
        node->lchild = erase(node->lchild, key);
    } else {
        if (node->lchild == NULL && node->rchild == NULL) {
            free(node);
            return NULL;
        } else if (node->lchild == NULL || node->rchild == NULL) {
            Node *temp = (node->lchild ? node->lchild : node->rchild);
            free(node);
            return temp;
        } else {
            Node *temp = predecessor(node);
            node->data = temp->data;
            node->lchild = erase(node->lchild, temp->data);
        }
    }
    return node;
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
    Tree t = init(5);
    for (int i = 0; i < 10; i++) {
        int op = rand() % 5;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                int val = rand() % 10;
                insert(t, val);
                printf("insert : %d\n", val);
                output(t);
                printf("\n");
                break;
            }
            case 3: {
                int val = rand() % 10;
                printf("search %d from t is %d\n", val, search(t, val));
                output(t);
                printf("\n");
                break;
            }
            case 4: {
                int val = rand() % 10;
                printf("erase %d \n", val);
                erase(t, val);
                output(t);
                printf("\n");
                break;
            }
        }
    }
    clear(t);
    return 0;
}

