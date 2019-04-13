/*************************************************************************
	> File Name: 378.有序矩阵中第K小的元素.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月08日 星期一 11时38分52秒
 ************************************************************************/

#include <stdio.h>


int kthSmallest(int** matrix, int matrixRowSize, int matrixColSize, int k) {
    #define MAX 0x7FFFFFFF
    int ans[k];
    for (int i = 0; i < k; i++) {
        ans[i] = MAX;
    }
    for (int i = 0; i < matrixRowSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            insertHeap(ans, matrix[i][j]);
        }
    }
    
    
    
    
    
    #undef MAX
}
