/*************************************************************************
	> File Name: string.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月10日 星期一 19时17分03秒
 ************************************************************************/
#include <stdio.h>

int (*sp)(int matrix[100][100], int m, int n) {
    int t;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n / 2; j++) {
                    t = *(matrix[i] + j);
            *(matrix[i] + j) = *(matrix[i] + n - j - 1);
            *(matrix[i] + n - j - 1) = t;
      	}
    }
    return matrix;
}

int * sz(int matrix[][100], int m, int n) {
    int t;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m / 2; i++) {
        	t = matrix[i][j];
            //matrix[i][j] = matrix[m - 1 - i][j];
             *(matrix * i + j) = *(matrix * (m - 1 - i) + j);
            matrix[m - 1 - j][j] = t;
      	}
    }
    return matrix;
} 

void sc(int matrix[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j != n - 1) 
                printf("%d ", matrix[i][j]);
            else 
                printf("%d", matrix[i][j]);
    
    }
}
int main() {
    int matrix[100][100];
    int m;
    int n;
    int f;
    while (scanf("%d%d", &m, &n) != EOF) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        scanf("%d", &f);
        
        switch(f) {
            //case 0:matrix=sz(matrix, m, n); sc(matrix, m, n);
            case 1:sc(sp(matrix, m, n), m, n);
        }
    }


    return 0;
}
