/*************************************************************************
	> File Name: 14.binary_haffman_trie.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月23日 星期三 10时56分33秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 二叉字典树，可一次性输入多个单词，多次进行查找单词是否存在
 * 思路：插入操作时先统计单词中每个字母出现的次数，确定每个字母的权值，对每个字母进行哈夫曼编码
 * 然后根据字母的编码组合出单词对应的编码，将单词0/1编码插入到字典树中
 * 查询操作时，先将所查单词根据编码规则进行单词编码，如果遇到编码规则中不存的字母直接查找失败。
 */

//哈夫曼编码
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
    char buff[20];
    extract_code(root, code, 0, buff);
}

/*
 * 二叉字典树
 */
typedef struct Trie {
    int flag;
    struct Trie *lchild, *rchild;
}Trie;

Trie *getNewTrie() {
    Trie *p = (Trie *)calloc(sizeof(Trie), 1);
    return p;
}

void insert(Trie *root, const char *str) { 
    Trie *p = root;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            if (p->lchild == NULL) {
                p->lchild = getNewTrie();
            }
            p = p->lchild;
        } else if (str[i] == '1') {
            if (p->rchild == NULL) {
                p->rchild = getNewTrie();
            }
            p = p->rchild;
        }
    }
    p->flag = 1;
    return ;
}

int search(Trie *root, const char *str) {
    Trie *p = root;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            if (p->lchild == NULL) {
                return 0;
            }
            p = p->lchild;
        } else if (str[i] == '1') {
            if (p->rchild == NULL) {
                return 0;
            }
            p = p->rchild;
        }
    }
    return p->flag;
}

void clear_Trie(Trie *trie) {
    if (trie == NULL) return ;
    clear_Trie(trie->lchild);
    clear_Trie(trie->rchild);
    free(trie);
    return ;
}

void Transform(char **buff, char **code, char **string_encoding, int n) {    
    for (int i = 0; i < n; i++) {
        for (int j = 0; buff[i][j]; j++) {
            strcat(string_encoding[i], code[buff[i][j]]);
        }
    }
}

int main() {
    int n = 0;
    int str[26] = {0};
    scanf("%d", &n);
    char **buff = (char **)calloc(sizeof(char *), 50);
    for (int i = 0; i < 50; i++) {
        buff[i] = (char *)calloc(sizeof(char), 50);
    }
    char **string_encoding = (char **)calloc(sizeof(char *), 50);
    for (int i = 0; i < 50; i++) {
        string_encoding[i] = (char *)calloc(sizeof(char), 1000);
    }
    /*
     * 录入n个单词至buff数组中,string_encoding代表单词转为哈夫曼编码后的形式
     * str数组代表每个字母的个数即权值,code数组代表每个字母的编码
     */
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
    char **code = (char **)calloc(sizeof(char *), 256);
    for (int i = 0; i < 256; i++) {
        code[i] = (char *)calloc(sizeof(char), 20);
    }
    func(cnt, str, code);
    Transform(buff, code, string_encoding, n);
    Trie *root = getNewTrie();
    for (int i = 0; buff[i]; i++) {
        insert(root, string_encoding[i]);
    }
    char ans[50];
    int flag = 0;
    while (scanf("%s", ans) != EOF) {
        flag = 1;
        char *ans_encoding = (char *)calloc(sizeof(char), 50);
        for (int i = 0; i < strlen(ans); i++) {
            if (str[ans[i] - 'a'] == 0) {
                flag = 0;
                break;
            }
            strcat(ans_encoding, code[ans[i]]);
        }
        if (flag) {
            printf("search %s is %d\n", ans, search(root, ans_encoding));   
        } else {
            printf("search %s is 0\n", ans);
        }
    }
    return 0;
}

