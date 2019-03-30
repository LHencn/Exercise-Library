/*************************************************************************
	> File Name: 07.statble_sort.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月27日 星期三 10时18分49秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define swap(a, b) ({\
    a ^= b ^= a ^= b;\
})

#define TEST(arr, n, func, args...) {

}


void bubble_sort(int *num, int n) {
    int times = 1;
    for (int i = 1; i < n && times; i++) {
        times = 0;
        for (int j = 0; j < n - i; j++) {
            if (num[j] > num[j + 1]) {
                swap(num[j], num[j + 1]);
                times++;
            }
        }
    }
    return ;
}

void insert_sort(int *num, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
            swap(num[j], num[j - 1]);
        }
    }
    return ;
}

void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[l] > num[r]) 
            swap(num[l], num[r]);
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) 
            temp[k++] = num[p1++];
        else 
            temp[k++] = num[p2++];
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
}




int main() {
    srand(time(0));
    #define MAX 20 
    int arr[MAX];
    randint(arr, MAX);
    TEST(arr, MAX, insert_sort, num, )
    
    
    
    
    
    
    
    {
        int a[] = {3, 4, 5, 6, 7, 1, 2, 8, 9};
        bubble_sort(a, 9);
        for (int i = 0; i < sizeof(a) / sizeof(*a); i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    {
        int a[] = {3, 4, 5, 6, 7, 1, 2, 8, 9};
        insert_sort(a, 9);
        for (int i = 0; i < sizeof(a) / sizeof(*a); i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    {
        int a[] = {3, 4, 5, 6, 7, 1, 2, 8, 9};
        merge_sort(a, 0, 8);
        for (int i = 0; i < sizeof(a) / sizeof(*a); i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
