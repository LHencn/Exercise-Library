/*************************************************************************
	> File Name: 01.sequence_table.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年02月07日 星期四 16时27分12秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
	int length, size;
    int *data;
} Vector;

void init(Vector *vector, int size) {
	vector->size = size;
    vector->data = (int *)malloc(sizeof(int) * size);
    vector->length = 0;
}

void expand(Vector *vector) {
	int *temp = vector->data;
    vector->size = 2 * vector->size;
    vector->data = (int *)malloc(sizeof(int) * vector->size);
    for (int i = 0; i < vector->length; i++) {
        vector->data[i] = temp[i];
    }
    free(temp);
}

int insert(Vector *vector, int loc, int value) {
	if (loc < 0 || loc > vector->length) {
        return ERROR;
    }
    if (vector->length == vector->size - 1) {
        expand(vector);
    }
    for (int i = vector->length; i > loc; i--) {
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[loc] = value;
    vector->length++;
    return OK;
}

int search(Vector *vector, int value) {
	for (int i = 0; i < vector->length; i++) {
        if (value == vector->data[i]) {
            return OK;
        }
    }
    return ERROR;
}

int delete_node(Vector *vector, int index) {
	if (index < 0 || index >= vector->length) {
         return ERROR;
     }
    for (int i = index; i < vector->length; i++) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->length--;
    return OK;
}

void print(Vector *vector) {
	for (int i = 0; i < vector->length; i++) {
        if (i == 0) {
            printf("%d", vector->data[i]);
            continue;
        }
        printf(" %d", vector->data[i]);
    }
    printf("\n");
}

void clear(Vector *vector) {
	free(vector->data);
    free(vector);
}

int main() {
    Vector *a = (Vector *)malloc(sizeof(Vector));
    init(a, 20);
	int m, t, p, q;
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &t);
        switch(t) {
            case 1: {
                scanf("%d%d", &p, &q);
                if (insert(a, p, q)) {
                    printf("success\n");
                } else {
                    printf("failed\n");
                }
                break;
            }
            case 2: {
                scanf("%d", &p);
                if (delete_node(a, p)) {
                    printf("success\n");
                } else {
                    printf("failed\n");
                }
                break;
            }
            case 3: {
                scanf("%d", &p);
                if (search(a, p)) {
                    printf("success\n");
                } else {
                    printf("failed\n");
                }
                break;
            }
            case 4: {
                print(a);
                break;
            }
        }
    }
    clear(a);
    return 0;
}

