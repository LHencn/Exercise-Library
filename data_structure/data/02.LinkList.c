/*************************************************************************
	> File Name: 08.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年02月10日 星期日 12时08分06秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct LinkList {
    LinkNode head;
    int length;
}LinkList;

LinkList *init() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

LinkNode *getNewNode(int val) {
    LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
    p->data = val;
    p->next = NULL;
    return p;
}

void insert(LinkList *l, int loc, int val) {
    LinkNode *node = getNewNode(val);
    LinkNode *p = &(l->head);
    while (loc--) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    l->length++;
}

void erase(LinkList *l, int loc) {
    LinkNode *p = &(l->head);
    while (loc--) {
        p = p->next;
    }
    LinkNode *temp = p->next;
    p->next = p->next->next;
    free(temp);
    l->length--;
}

void output(LinkList *l) {
    LinkNode *p = l->head.next;
    printf("[%d] ", l->length);
    while (p) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void clear(LinkList *l) {
    LinkNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    free(l);
}

int main() {
    srand(time(0));
    int op, loc, val;
    LinkList *l = init();
    for (int i = 0; i < 40; i++) {
        op = rand() % 5;
        switch(op) {
            case 0:
            case 1:
            case 2:
            case 3:{
                loc = rand() % (l->length + 1);
                val = rand() % 100;
                printf("insert(l, %d, %d)\n", loc, val);
                insert(l, loc, val);
                output(l);
                break;
            }
            case 4: {
                if (l->length == 0) break;
                loc = rand() % l->length;
                printf("erase(l, %d)\n", loc);
                erase(l, loc);
                output(l);
                break;
            }
        }
    }
    clear(l);
    return 0;
}
