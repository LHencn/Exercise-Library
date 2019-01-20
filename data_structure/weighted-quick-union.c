/*************************************************************************
	> File Name: weight_quick_union.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月20日 星期日 16时48分27秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct UnionSet {
    int *father; 
    int *size;
    int n;
}UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)calloc(sizeof(UnionSet), 1);
    u->father = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        u->father[i] = i;
        u->size[i] = 1;
    }
    u->n = n;
    return u;
}

int find(UnionSet *u, int x) {
    if (u->father[x] != x) return find(u, u->father[x]);
    return x;
}

int merge(UnionSet *u, int a, int b){
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
    if (u->size[fa] < u->size[fb]) {
        fa ^= fb ^= fa ^= fb;
    }
        u->father[fa] = fb;
        u->size[fb] += u->size[fa];
    return 1;
}


void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->father);
    free(u);
    return ;
}

void output(UnionSet *u) {
    for (int i = 0; i < u->n; i++) {
        printf("(%d, %d)\t", i, u->father[i]);
        if (i + 1 < u->n && i + 1 % 5 == 0) printf("\n");
    }
}
int main() {
    srand(time(0));
    int op, a, b;
    #define MAX_OP 10
    #define MAX_N 10
    UnionSet *u = init(MAX_N);
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 4;
        a = rand() % MAX_N;
        b = rand() % MAX_N;
        switch (op) {
            case 0: {
                printf("find %d <-> %d = %d\n", a, b, find(u, a) == find(u, b));
                break;
            }
            default: {
                printf("union %d <-> %d = %d\n", a, b, merge(u, a, b));
            }
        }
    }

    return 0;
}
