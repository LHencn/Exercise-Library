/*************************************************************************
	> File Name: 1.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年12月10日 星期一 20时32分06秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    int ind;
}Node;

typedef struct HashTable {
    Node *data;
    int size;
}HashTable;

HashTable *init_hashtable(int size) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = 2 * size;
    h->data = (Node *)malloc(sizeof(Node) * h->size);
    return h;
}

void init_node(Node *node, int val, int ind) {
    node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->ind = ind;
    return ;
}

int insert(HashTable *h, int val, int ind) {
    
}


void clear_node(Node *node) {
    if(node == NULL) return ;
    free(node);
    return ;
}

void clear_hashtable(HashTable *h) {
    if(h == NULL) return ;
    for (int i = 0; i < h->size; i++) {
        if (h->data != NULL) {
            clear_node(h->data[i]);
        }
    }
    free(h->data);
    free(h);
    return ;
}

int main() {

}
