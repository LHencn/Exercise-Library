/*************************************************************************
	> File Name: 09.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年02月14日 星期四 09时27分04秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
}Node;

Node *getNewNode(int n) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = n;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *node, int val) {
    if (node == NULL) return getNewNode(val);
    if (val == node->data) return node;
    if (val > node->data) 
        node->rchild = insert(node->rchild, val);
    else if (val < node->data) 
        node->lchild = insert(node->lchild, val);
    return node;
}

Node *predecessor(Node *node) {
    Node *temp = node->lchild;
    while (temp->rchild) temp = temp->rchild;
    return temp;
}

Node *erase(Node *node, int val) {
    if (node == NULL) return node;
    if (val > node->data) 
        node->rchild = erase(node->rchild, val);
    else if (val < node->data)
        node->lchild = erase(node->lchild, val);
    else {
        if (node->lchild == NULL && node->rchild == NULL) {
            free(node);
            return NULL;
        } else if (node->lchild == NULL || node->rchild == NULL) {
            Node *temp = node->lchild ? node->lchild : node->rchild;
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

int search(Node *node, int val) {
    if (node == NULL) return 0;
    if (val == node->data) return 1;
    else if (val > node->data) {
        return search(node->rchild, val);
    } else {
        return search(node->lchild, val);
    }
}

void output(Node *node) {
    if (node == NULL) return ;
    output(node->lchild);
    printf(" %d", node->data);
    output(node->rchild);
}

void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
}

int main() {
    Node *root;
    srand(time(0));
    for (int i = 0; i < 40; i++) {
        int op = rand() % 5;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                int val = rand() % 100;
                root = insert(root, val);
                printf("[insert %3d]", val);
                output(root);
                printf("\n");
                break;
            }
            case 3: {
                int val = rand() % 100;
                root = erase(root, val);
                printf(" [erase %3d]", val);
                output(root);
                printf("\n");
                break;
            }
            case 4: {
                int val = rand() % 100;
                printf("[search %3d] is %d\n", val, search(root, val));
                break;
            }
        }
    }
    clear(root);
    return 0;
}


