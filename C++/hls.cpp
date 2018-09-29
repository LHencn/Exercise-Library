/*************************************************************************
	> File Name: hls.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月13日 星期四 16时20分20秒
 ************************************************************************/


#include <stdio.h>

int main() {
    int A[4][4], B[3][3];
    int sumA, sumB;
    int f = 1;
   // while (1) {
        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                scanf("%d", (A[i] + j));
            }
        }
        printf("1");
        sumA = A[1][1] * A[2][2] * A[3][3] + A[1][2] * A[2][3] * A[3][1]
            + A[1][3] * A[2][1] * A[3][2] - A[1][3] * A[2][2] * A[3][1]
            - A[1][1] * A[2][3] * A[3][2] - A[1][2] * A[2][1] * A[3][3];

        for (int i = 1; i < 3; i++) {
            for (int j = 1; j < 3; j++) {
                scanf("%d", (B[i] + j));
            }
        }

        sumB = B[1][1] * B[2][2] - B[1][2] * B[2][1];
        //printf("%d\n", sumA);
        //printf("%d", sumA > sumB ? sumA : sumB);
   // }
    return 0;
}
