/** @file log.c */
#include <stdlib.h>
#include <string.h>
#include "log.h"

/**
对log进行初始化，log的“构造函数”
 */

void log_init(log_t *l) {
    l->head = NULL;
    return ;
}

/**
销毁一个log，释放所有内存空间，log的“析构函数”
 */

void log_destroy(log_t* l) {
    node *p = l->head, *q = NULL;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    free(l);
    return ;
}

/**
向log中推入一个字符串，你可以将log视为一个由链表组成的栈
 */

void log_push(log_t* l, const char *item) {
    if (l->head == NULL) {
        l->head = malloc(sizeof(node));
        l->head->cmd = malloc(sizeof(char) * (strlen(item) + 1));
        strcpy(l->head->cmd, item);
        l->head->next = NULL;
        return ;
    }
    node *p = l->head;
    while (p->next) {
        p = p->next;
    }
    node *q = malloc(sizeof(node));
    q->cmd = malloc(sizeof(char) * (strlen(item) + 1));
    strcpy(q->cmd, item);
    q->next = NULL;
    p->next = q;
    return ;
}


/**
搜索log中是否含有对应前缀的字符串
 */

char *log_search(log_t* l, const char *prefix) {
    node *p = l->head;
    while (p) {
        for (int i = 0; prefix[i]; i++) {
            if (prefix[i] != p->cmd[i]) break;
            if (prefix[i + 1] == '\0') 
                return p->cmd;
        }
        p = p->next;
    }
    return NULL;
}
