/*************************************************************************
	> File Name: 12.haffman.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月22日 星期二 21时27分29秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key, freq; //key代表字母，freq代表权值
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

int swap_node(Node **p, Node **q) {
    Node *temp = *p;
    *p = *q;
    *q = temp;
    return 1;
}

Node *build_haffman(Node **arr, int n) {
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 2; j++) {
            if (arr[j]->freq < arr[n - i - 1]->freq) {
                swap_node(arr + j, arr + n - i - 1);
            }
            if (arr[j]->freq < arr[n - i - 2]->freq) {
                swap_node(arr + j, arr + n - i - 2);
            }
        }
        Node *temp = getNewNode(0, arr[n - i - 1]->freq + arr[n - i - 2]->freq);
        temp->lchild = arr[n - i - 1];
        temp->rchild = arr[n - i - 2];
        arr[n - i - 2] = temp;
    }
    return arr[0];
}

void extract_code(Node *root, char **code, int k, char *buff) {
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

void func(int n, int *str, char** code) {
    Node **arr = (Node **)malloc(sizeof(Node *) * n);
    Node *root;
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (str[i] == 0) continue;
        arr[cnt] = getNewNode(i + 97, str[i]);
        cnt++;
    }
    root = build_haffman(arr, n);
    //char code[256][20] = {0}, buff[20];
    char buff[20];
    extract_code(root, code, 0, buff);
}

int main() {
    int n = 0;
    int str[26] = {0};
    char buff[50][50];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff[i]);
        for (int j = 0; buff[i][j]; j++) {
            str[buff[i][j] - 'a']++;
        }
    }
    int cnt = 0; 
    for (int i = 0; i < 26; i++) {
        if (str[i] != 0) 
            cnt++;
    }
    
    for (int i = 0; i < 26; i++) {
        printf("%c is %d\n", i + 'a', str[i]);
    }
    printf("%d\n", cnt);
    char **code = (char **)calloc(sizeof(char *), 256);
    for (int i = 0; i < 256; i++) {
        code[i] = (char *)calloc(sizeof(char), 20);
    }
    func(cnt, str, code);

    return 0;
}

