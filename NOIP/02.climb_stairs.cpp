/*************************************************************************
	> File Name: 02.climb_stairs.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月28日 星期一 14时18分58秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define MAX 1000

int a[MAX + 5] = {1, 0, 1, 1};
int f(int n) { //递推+记忆化，时间复杂度为O(N)
    if (n < 4) 
        return a[n];
    if (a[n] == 0)
        a[n] = f(n - 2) + f(n - 3);
    return a[n];
}

int g(int n) { //从第1阶开始循环求解,采用滚动数组压缩空间
    int b[4] = {1, 0, 1, 1};
    if (n < 4) 
        return b[n];
    for (int i = 4; i <= n; i++) {
        b[i % 4] = b[(i - 3) % 4] + b[(i - 2) % 4];
    }
    return b[n % 4];
}


int main() {
    int n;
    while (cin >> n) {
        cout << "num: " << g(n) << endl;
    }
    return 0;
}
