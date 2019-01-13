/*************************************************************************
	> File Name: test.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月11日 星期五 17时52分34秒
 ************************************************************************/

#include<stdio.h>
void dectobin( int n ){
int result=0,k=1,i,temp;
temp = n;
while(temp){
i = temp%2;
result = k * i + result;
k = k*10;
temp = temp/2;
}

    printf("十进制为 %d, 二进制为 %d\n", n, result);
}

int main() {

    int n;
    while (1) {
    scanf("%d", &n);
    dectobin(n);

    }
    return 0;
}
