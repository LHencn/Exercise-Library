/*************************************************************************
	> File Name: 16.AVL.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月25日 星期五 15时06分27秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#define max(a, b) {(\
    __typeof(a) __a = (a);\
    __typeof(b) __b = (b);\
    __a > __b ? __a : __b;\
                   )}

typedef struct Node {
    int key;
    int height;
    struct Node *lchild, *rchild;
}Node;

Node *NIL; //虚拟节点高度为0

Node *init(int key) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->key = key;
    p->height = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

__attribute__((construtor))
void init_NIL() {
    NIL = init(0);
    NIL->height = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

void calc_height(Node *root) {
    root->height = max(root->lchild->height, root->rchild->height) + 1;
}
Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;

}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
}


Node *maintain(Node *root) {
    if (abs(root->lchild->height - root->rchild->height) <= 1) return root;
    if (root->lchild->height > root->rchild->height) {
        if (root->lchild->lchild->height < root->lchild->rchild->height) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        
    }
}

Node *insert(Node *root, int key) {
    if (root == NULL) return init(key);
    if (root->key = key) return root;
    else if (root->key < key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    return maintain(root);
}

Node *predecossor(Node *root) {
    Node *temp = 
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key < key) {
        root->rchild = erase(root->rchild, key);
    } else if (root->key > key) {
        root->lchild = erase(root->lchild, key);
    } else {
        if (root->lchild == NIL && root->rchild == NIL) {
            free(root);
            return NIL;
        } else if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = (root->lchild != NIL ? root->lchild : root->rchild);
            free(root);
            return temp;
        } else {
            Node *temp = predecossor(root);
            root->key = temp->key;
            root = erase(root->lchild, temp->key);
        }
    }
    calc_height(root);
    return maintain(root);
}

void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("(%d, %d, %d)\n", root->key, root->lchild->key, root->rchild->key);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (scanf("%d%d", &op, &val) != EOF) {
        switch(op) {
            case 1: insert(root, val); break;
            case 2: erase(root, val); break;
        }
        output(root);
    }

    return 0;
}
