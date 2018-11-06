/*************************************************************************
	> File Name: haffman.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月28日 星期日 20时01分39秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

typedef struct Node {
    int key, freq;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key, int freq) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->freq = freq;
    p->lchild = p->rchild = NULL;
    return p;

}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void swap_node(Node *p, Node *q) {
    Node temp = *p;
    *p = *q;
    *q = temp;
    return ;
}


Node *build_haffman(Node **arr, int n) {
    /*Node INIT_NODE = {0, INT32_MAX, NULL, NULL};
    Node *first = &INIT_NODE, *second = &INIT_NODE;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[i]->freq < first->freq) {
                second = first;
                first = arr[i];
            } else if (arr[i]->freq < second->freq) {
                second = arr[i];
            }
        }
        Node *temp = getNewNode(0, first->freq + second->freq);
        temp->lchild = first;
        temp->rchild = second;
        swap_node(arr[n - i - 1], first);
        swap_node(arr[n - i - 2], second);
        arr[n - i - 2] = temp;
        printf("first : %c, %d, second : %c, %d\n", )
    }*/
    for (int i = 0; i < n - 1; i++) {
        int ind1 = arr[0]->freq > arr[1]->freq;
        int ind2 = arr[0]->freq <= arr[1]->freq;
        printf("init : %d, %d\n", ind1, ind2);
        for (int j = 2; j < n - i; j++) {
            if (arr[j]->freq < arr[ind1]->freq) {
                ind2 = ind1;
                ind1 = j;
            } else if (arr[j]->freq < arr[ind2]->freq) {
                ind2 = j;
            }
        }
        printf("first : %c, %d, second : %c, %d\n", arr[ind1]->key, arr[ind1]->freq, arr[ind2]->key, arr[ind2]->freq);
        Node *temp = getNewNode(0, arr[ind2]->freq + arr[ind1]->freq);
        temp->lchild = arr[ind1];
        temp->rchild = arr[ind2];
        swap_node(arr[n - i - 1], arr[ind1]);
        swap_node(arr[n - i - 2], arr[ind2]);
        arr[n - i - 2] = temp;
    }
    return arr[0];
}

void extract_code(Node *root, char (*code)[20], int k, char *buff) {
    buff[k] = 0;
    if (root->key) {
        strcpy(code[root->key], buff);
        return ;
    }
    buff[k] = '0'; 
    extract_code(root->lchild, code, k + 1, buff);
    buff[k] = '1';
    extract_code(root->rchild, code, k + 1, buff); 
    return ;
}
int main() {
    int n;
    scanf("%d", &n);
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node *root;
    for (int i = 0; i < n; i++) {
        char key[10];
        int freq;
        scanf("%s%d", key, &freq);
        arr[i] = getNewNode(key[0], freq);
    }
    root = build_haffman(arr, n);

    char code[256][20] = {0}, buff[20];
    extract_code(root, code, 0, buff); 
    for (int i = 0; i < 256; i++) {
        if (code[i][0] == 0) continue;
        printf("%c : %s\n", i, code[i]);
    }

    printf("\n%c\n", 255);
    return 0;
}
