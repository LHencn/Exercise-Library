/*************************************************************************
	> File Name: priority_queue.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年11月01日 星期四 20时07分21秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef struct priority_queue {
    int *data;
    int cnt, size;
} priority_queue;

priority_queue *init(int n) {
    priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
    q->data = (int *)malloc(sizeof(int) * (n + 1));
    q->cnt = 0;
    q->size = n;
    return q;
}


void clear(priority_queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int empty(priority_queue *q) {
    
}


int push(priority_queue *q, int value) {

}

int pop(priority_queue *q) {

}

int top(priority_queue *q) {
    if (empty(q)) return 0;    
}

int main() {
    



    return 0;
}
