/*************************************************************************
	> File Name: 07.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年02月09日 星期六 12时46分32秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int *data;
    int size, length;
}Vector;

Vector *init(int n) {
    Vector *p = (Vector *)malloc(sizeof(Vector));
    p->size = n;
    p->length = 0;
    p->data = (int *)malloc(sizeof(int) * p->size);
    return p;
}

void expand(Vector *v) {
    int *temp = v->data;
    v->size = 2 * v->size;
    v->data = (int *)malloc(sizeof(int) * v->size);
    for (int i = 0; i < v->length; i++) {
        v->data[i] = temp[i];
    }
    free(temp);
}

int insert(Vector *v, int loc, int value) {
    if (loc < 0 || loc > v->length) 
        return 0;
    if (v->length == v->size) 
        expand(v);
    for (int i = v->length; i > loc; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[loc] = value;
    v->length++;
    return 1;
}

int erase(Vector *v, int loc) {
    if (loc < 0 || loc >= v->length) {
        return 0;
    }
    for (int i = loc; i < v->length - 1; i++) {
        v->data[i] = v->data[i + 1];
    }
    v->length--;
    return 1;
}

void output(Vector *v) {
    for (int i = 0; i < v->length; i++) {
        if (!i) {
            printf("%d", v->data[i]);
        } else {
            printf(" %d", v->data[i]);
        }
    }
    printf("\n");
}

void clear(Vector *v) {
    free(v->data);
    free(v);
}
int main() {
    Vector *v = init(5);
    #define MAX_OP 40
    for (int t = 0; t < MAX_OP; t++) {
        int op = rand() % 4, ind, value;
        switch (op) {
            case 4:
            case 2:
            case 3:
            case 0 : {
                ind = rand() % (v->length + 3) - 1;
                value = rand() % 100;
                printf("[%d] insert(v, %d, %d) to vector\n", insert(v, ind, value), ind, value);
                output(v);
            } break;
            case 1: {
                ind = rand() % (v->length + 3) - 1;
                printf("[%d] erase(%d) from vector\n", erase(v, ind), ind);
                output(v);
            } break;
        }
    }
    clear(v);
    return 0;
}

