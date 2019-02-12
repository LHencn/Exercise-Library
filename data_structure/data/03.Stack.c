/*************************************************************************
	> File Name: 03.Stack.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年02月11日 星期一 09时30分04秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int size, top;
}Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

int top(Stack *s) {
    return s->data[s->top];
}

void expand(Stack *s) {
    int *temp = s->data;
    s->size = 2 * s->size;
    s->data = (int *)malloc(sizeof(s->size));
    for (int i = 0; i < s->top + 1; i++) {
        s->data[i] = temp[i];
    }
}

void push(Stack *s, int val) {
    if (s->top == s->size - 1) 
        expand(s);
    s->top++;
    s->data[s->top] = val;
}

void pop(Stack *s) {
    s->top--;
}

void clear(Stack *s) {
    free(s->data);
    free(s);
}

void output(Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf(" %d", s->data[i]);
    }
    printf("\n");
}

int main () {
    Stack *s = init(10);
    srand(time(0));
    for (int i = 0; i < 40; i++) {
        int op = rand() % 5;
        switch (op) {
            case 0:
            case 1:
            case 2:
            case 3: {
                int val = rand() % 100;
                push(s, val);
                printf("[栈顶=%d]", top(s));
                output(s);
                break;
            }
            case 4: {
                pop(s);
                printf("[弹栈：]");
                output(s);
                break;
            }
        }
    }
    clear(s);
    return 0;
}

