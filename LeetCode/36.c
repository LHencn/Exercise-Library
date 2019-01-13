/*************************************************************************
	> File Name: 36.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月13日 星期日 18时58分46秒
 ************************************************************************/

#include<stdio.h>

bool isValidSudoku(char **board, int boardRowSize, int boardColSize) {
    int row[9] = {0}, column[9] = {0}, gong[9] = {0};
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            int val = board[i][j];
            if (row[i] & (1 << val)) return false;
            if (col[j] & (1 << val)) return false;

        }
    }
}



int main() {






    return 0;
}
