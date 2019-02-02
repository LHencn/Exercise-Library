/*************************************************************************
	> File Name: 17.Binary_Tree_to_Generalized_Table.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年02月02日 星期六 09时49分47秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
}Node;

Node *getNewNode(int value) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = value;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *node, int value) {
    if (node == NULL) {
        return getNewNode(value);
    if (value == node->data) return node;
    } else if (value > node->data) {
            node->rchild = insert(node->rchild, value);
    } else if (value < node->data) {
            node->lchild = insert(node->lchild, value);
    }
    return node;
}

int search(Node *node, int value) {
    if (node == NULL) {
        return 0;
    if (value == node->data) return 1;
    } else if (value > node->data) {
        return search(node->rchild, value);
    } else if (value < node->data) {
        return search(node->lchild, value);
    }
    return 0;
}

void clear(Node *node) {
    if (node == NULL) return ;
    clear(node->lchild);
    clear(node->rchild);
    free(node);
    return ;
}

void inorder(Node *node) {
    if (node == NULL) return ;
    inorder(node->lchild);
    printf("%d ", node->data);
    inorder(node->rchild);
    return ;
}

void tree_transform_to_table(Node *node) {
    printf("%d", node->data);
    int flag = 0;//代表栈
    if (node->lchild) {
        printf("(");
        flag += 1;
        tree_transform_to_table(node->lchild);
    }
    if (node->rchild) {
        printf(",");
        tree_transform_to_table(node->rchild);
        if (flag) {
            printf(")");
            flag -= 1;
        }
    }
    return ;
}

void table_transform_to_tree(Node *root, char *str) {
    int ans = 0;
    Node *node;
    int i;
    for (i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            ans = ans * 10 + (str[i] - '0');
        }
        if (str[i] == '(') {
            root = getNewNode(ans);
            break;
        }
    }
    for (; str[i]; i++) {
        
    }
}


int main() {
    Node *root;
    int a[10];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        root = insert(root, a[i]);
    }
    int value;
    scanf("%d", &value);
    printf("search value is : %d\n", search(root, value));
    inorder(root);
    tree_transform_to_table(root);
    clear(root);
    return 0;
}
