/*************************************************************************
	> File Name: 04.Queue.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年02月11日 星期一 09时47分47秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int size, first, last;
    int *data;
}Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->size = n;
    q->data = (int *)malloc(sizeof(int) * n);
    q->first = 0;
    q->last = 0;
    return q;
}

void expand(Queue *q) {
    int *temp = q->data;
    q->size = 2 * q->size;
    q->data = (int *)malloc(sizeof(q->size));
    for (int i = 0; i < q->last + 1; i++) {
        q->data[i] = temp[i];
    }
}

/*
void push(Queue *q, int val) {
    if (q->last == q->size - 1) 
        expand(q);
    q->last++;
    q->data[q->last] = val;
}*/

int push(Queue *q, int val) {
    if ((q->last + 1) % 10 == q->first) {//满队列,扩容操作？？？
        return 0;
    } else {
        q->data[q->last] = val;
        q->last++;
        return 1;
    }
}

int pop(Queue *q) {
    if (q->first == q->last) {
        return 0;
    }
    q->first++;
    return 1;
}
/*
void pop(Queue *q) {
    for (int i = 0; i < q->last; i++) {
        q->data[i] = q->data[i + 1];
    }
    q->last--;
}*/

void output(Queue *q) {
    if (q->first < q->last) {
        for (int i = q->first; i < q->last; i++) {
            printf(" %d", q->data[i]);
        }
    } else if (q->first > q->last) {
        for (int i = q->first; i < q->size; i++) {
            printf(" %d", q->data[i]);
        }
        for (int i = 0; i < q->last; i++) {
            printf(" %d", q->data[i]);
        }
    }
    printf("\n");
}

void clear(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *q = init(10);
    srand(time(0));
    for (int i = 0; i < 40; i++) {
        int op = rand() % 5;
        switch(op) {
            case 0:
            case 1:
            case 2:
            case 3: {
                int val = rand() % 100;
                push(q, val);
                printf("%d进入队列：", val);
                output(q);
                break;
            }
            case 4: {
                int val = rand() % 100;
                pop(q);
                printf("出队列：");
                output(q);
                break;
            }
        }
    }
    clear(q);
    return 0;
}

