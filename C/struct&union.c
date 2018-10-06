/*************************************************************************
	> File Name: struct&union.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月04日 星期四 10时18分11秒
 ************************************************************************/

#include<stdio.h>

struct person {
    char name[20];
    int age;
    char gender;
    float height;
};

struct test {
    short a;
    char b;
    int c;       //int类型在内存中只能放在以0、4、8开头
    double e;
}

struct Number {
    int type; //0->int or 1->double
    union {
        int num1;
        float num2;
    } N;
};

int main () {
    printf("sizeof(person) : %d\n", sizeof(struct person));
    printf("%p %p %p %p", &a.a, &a.b, &a.c);
    #define MAX_N 20
    Number arr[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        int op = rand() % 2;
        switch (op) {
            case 0: {
                int value = rand() % 100;
                set(arr + i, value);
            } break;
            
            case 1: {
                float value = (1.0 * (rand() % 10000) / 10000) * 100;
                set(arr + i, value);
            } break;
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        print(arr + i);
    }
    arr[0].N.num2 = 1.0;
    printf("arr[0].N.num1 = %d\n", arr[0].N.num1);
    printf("arr[0].N.num1 = %x\n", arr[0].N.num1);
    return 0;
}
