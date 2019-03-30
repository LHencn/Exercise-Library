#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <iostream>
using namespace std;
#define swap(a, b) { \
    __typeof(a) _temp = a; a = b; b = _temp; \
}
#define __DBG
#ifdef  __DBG
#define DBG(a) printf("%d\n", a);
#endif 

#define op 1000000


void output(int *, int);

void heap_sort1(int *arr, int n) {
    int *p = arr - 1;
    for (int i = 2; i <= n; i++) {
        int ind = i, temp = ind;
        while (ind > 1) {
            if (p[ind] < p[ind >> 1]) break;
            swap(p[ind], p[ind >> 1]);
            ind = ind >> 1;
        }
    }
    for (int i = n; i > 1; i--) {
        swap(p[i], p[1]);
        int ind = 1;
        int temp = p[ind];
        while ((ind << 1) <= i - 1) {
            int tem = ind << 1;
            if ((ind << 1 | 1) <= i - 1 && (p[ind << 1 | 1] > p[ind << 1])) tem = ind << 1 | 1;
            if (p[tem] < temp) break;
            else p[ind] = p[tem];
            ind = tem;
        }
        p[ind] = temp;
    }
}

void heap_sort2(int *arr, int n) {
    int *p = arr - 1;
    for (int i = 2; i <= n; i++) {
        int ind = i;
        while (ind > 1) {
            if (p[ind] <= p[ind >> 1]) break;
            swap(p[ind], p[ind >> 1]);
            ind >>= 1;
        }
    }
    for (int i = n; i > 1; i--) {
        swap(p[i], p[1]);
        int ind = 1;
        while ((ind << 1) <= i - 1) {
            int temp = ind;
            if (p[temp] < p[ind << 1]) temp = ind << 1;
            if ((ind << 1 | 1) <= i - 1 && p[temp] < p[ind << 1 | 1]) temp = ind << 1 | 1;
            if (temp == ind) break;
            swap(p[temp], p[ind]);
            ind = temp;
        }
    }
    return ;
}


long long getCurrentTime(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int verify(int a[]){
	for(int i = 0; i < op - 1; i++){
		if(a[i] > a[i+1])
			return -1;
	}
	return 0;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        (i == 0 && printf("%d", arr[i]) || printf(" %d", arr[i]));
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int arr[op];
    int arr2[op];
    for (int i = 0; i < op; i++) {
        arr[i] = rand() % 100;
        arr2[i] = arr[i];
    }

    long long time_3_1 = getCurrentTime();
    heap_sort1(arr, op);
	long long time_3_2 = getCurrentTime();
    heap_sort2(arr2, op);
    long long time_3_3 = getCurrentTime();
	cout << time_3_2 - time_3_1 << "   " << time_3_3 - time_3_2 << endl;
	int c1 = verify(arr);
    int c2 = verify(arr2);
	cout << c1 << " " << c2 << endl;

    return 0;
}
