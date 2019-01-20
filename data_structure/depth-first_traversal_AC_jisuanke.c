/*************************************************************************
	> File Name: depth-first_traversal_AC_jisuanke.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月20日 星期日 11时10分14秒
 ************************************************************************/

/*
 * 计蒜客AC复习
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;
const char BASE = 'a';
const int MAX_SIZE = 200000;
const int MAX_LEN = 200000;
char str_buffer[200005];

typedef struct TrieNode {
    int count;
    struct TrieNode** childs;
    struct TrieNode* fail, *father;
} TrieNode, *Trie;

TrieNode* new_node() {
    TrieNode *p = (TrieNode *)malloc(sizeof(TrieNode));
    p->childs = (TrieNode **)malloc(sizeof(TrieNode *) * SIZE);
    for (int i = 0; i < SIZE; i++) {
        p->childs[i] = NULL;
    }
    p->fail = NULL;
    p->count = 0;
    p->father = NULL;
    return p;
}

void clear(TrieNode *node) {
    if (node == NULL) return ;
    for (int i = 0; i < SIZE; i++) {
        if (node->childs[i] == NULL) continue;
        clear(node->childs[i]);
    }
    free(node->childs);
    free(node);
    return ;
}

void insert(TrieNode *trie, const char *buffer) {
    TrieNode *p = trie;
    for (int i = 0; i < strlen(buffer); i++) {
        if (p->childs[buffer[i] - BASE] == NULL) {
            p->childs[buffer[i] - BASE] = new_node();
            p->childs[buffer[i] - BASE]->father = p;
        }
        p = p->childs[buffer[i] - BASE];
    }
    p->count++;
    return ;
}

void build_automaton(TrieNode *node) {
    TrieNode **queue = (TrieNode **)malloc(sizeof(TrieNode *) * (MAX_SIZE + 5));
    int head = 0, tail = 0;
    queue[tail++] = node;
    while (head < tail) {
        TrieNode *now = queue[head++];
        for (int i = 0; i < SIZE; i++) {
            if (now->childs[i] == NULL) continue;
            TrieNode *p = now->fail;
            while (p && p->childs[i] == NULL) p = p->fail;
            if (p == NULL) p = node;
            else p = p->childs[i];
            now->childs[i]->fail = p;
            queue[tail++] = now->childs[i];
        }
        for (int i = 0; i < SIZE; i++) {
            if (now->childs[i]) continue;
            now->childs[i] = now[fail]->childs[i];
        }
    }
    return ;
}

int match_count(TrieNode *ac_tree, const char *str) {
    int ret = 0;
	TrieNode *p = ac_tree, *q;
	while (str[0]) {
		while (p && p->childs[str[0] - 'a'] == NULL) p = p->fail;
        if (p == NULL) p = ac_tree;
        else p = p->childs[str[0] - 'a'];
        q = p;
		while (q) ret += q->count, q = q->fail;
		str++;
	}
	return ret;
}

int main() {
    Trie root = new_node();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char pattern[MAX_LEN];
        scanf("%s", pattern);
        insert(root, pattern);
    }
    build_automaton(root);
    scanf("%s", str_buffer);
    printf("%d\n", match_count(root, str_buffer));
    //clear(root);
    return 0;
}
