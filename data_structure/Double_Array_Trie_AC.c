/*************************************************************************
	> File Name: Double_Array_Trie_AC.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月20日 星期日 15时15分09秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BASE 26
typedef struct Node {
    int flag;
    struct Node *next[26];
}Node;

typedef struct DATNode {
    int base, check;
}DATNode;


Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    return p;
}

int insert(Node *node, const char *str) {
    Node *p = node;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - 'a'] == NULL) {
            p->next[str[i] - 'a'] = getNewNode();
        }
        p = p->next[str[i] - 'a'];
        cnt++;
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < 26; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int getBase(Node *node, DATNode *trie) {
    int base = 0, flag = 1;
    while (!flag) {
        flag = 1;
        base++;
        for (int i = 0; i < 26; i++) {
            if (node->next[i] == NULL) continue;
            if (trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
    }
    return base;
}


void Transform(Node *node, DATNode *trie, int ind) {
    if (ndoe->flag) trie[iind].check = -trie[ind].check;
    trie[ind].base = getBase(node, trie);
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        trie[trie[ind].base + i].check = ind;
    }
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        Transform(node->next[i], trie, trie[ind].base + i);
    }
    return ;
}

int search(DATNode *trie, const char *str) {
    int p = 1;
    for (int i = 0; str[i]; i++) {
        int delta = str[i] - 'a';
        int check = abs(trie[trie[p].base + delta].check);
        if (check - p) return 0;
        p = trie[p].base +  
    }
    return trie[p].check < 0;
}

int has_child(DATNode *node, int p, int i) {
    return abs(trie[trie[p].base + i].check) == p;
}

void build_ac(DATNode *trie, int cnt) {
    int *queue = (int *)malloc(sizeof(int) * (cnt + 5));
    int head = 0, tail = 0;
    trie[1].fail = 0;
    queue[tail++] = 1;
    while (head < tail) {
        int now = queue[head++];
        for (int i = 0; i < 26; i++) {
            if (!has_child(trie, now, i)) continue;
            int p = trie[now].fail;
            while (p && !has_child(trie, p, i)) p = trie[p].fail;
            if (p == 0) p = 1;
            else p = trie[p].base + i;
            trie[trie[now].base + i].fail = p;
            queue[tail++] = trie[now].base + i;
        }
    }
    return ;
};

int match_count(DATNode *trie, const char *str) {
    int ret = 0;
    int p = 1, q;
    while (str[0]) {
        while (p && !has_child(trie, p, str[0] - 'a')) p = trie[p]->fail;
        q = p;
        while (q) ret += (trie[q].check < 0), q = trie[q].fail;
        if (p == 0) p = 1;
        str++;
    }
    return ret;
}

int main() {
    int n, cnt = 0;
    char str[100];
    scanf("%d", &n);
    Node *root = getNewNode();
    while (n--) {
        scanf("%s", str);
        cnt += insert(root, str);
    }
    DATNode *trie = (DATNode *)calloc(sizeof(DATNode), cnt * 10);
    Transform(root, trie, 1);
    while (scanf("%s", str) != EOF) {
        printf("search %s = %d\n", )
    }
    return 0;
}

