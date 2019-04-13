/*************************************************************************
	> File Name: 08.priority_queue.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月09日 星期二 20时03分55秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) { \
    __typeof(a) temp = a; a = b; b = temp; \
}

typedef struct prioQueue {
    int *data; //存放权值大小
    int cnt, size;
} prioQueue;

int push(prioQueue *q, int value) {
    if (q->cnt == q->size) return 0;
    q->data[++(q->cnt)] = value;
    int ind = q->cnt;
    while (ind > 1) {
        if (q->data[ind] <= q->data[ind >> 1]) break;
        swap(q->data[ind], q->data[ind >> 1]);
        ind >> 1;
    }
    return 1;
}

int empty(prioQueue *q) {
    return (q->cnt == 0);
}

int pop(prioQueue *q) {
    if (empty(q)) return 0;
    q->data[1] = q->data[(q->cnt)--];
    int ind = 1;
    while ((ind << 1) <= q->cnt) {
        int temp = ind;
        if (q->data[temp] < q->data[ind << 1]) temp = ind << 1;
        if ((ind << 1 | 1) <= q->size && q->data[temp] < q->data[ind << 1 | 1]) temp = ind << 1 | 1;
        if (temp == ind) break;
        swap(q->data[ind], q->data[temp]);
        ind = temp;
    }
    return 1;
}

void clear(prioQueue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {

    return 0;
}
