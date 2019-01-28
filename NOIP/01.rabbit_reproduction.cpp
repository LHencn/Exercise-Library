/*************************************************************************
	> File Name: rabbit_reproduction.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月25日 星期五 09时58分25秒
 ************************************************************************/

/*
 * 兔子繁殖问题：如果有一对小兔，每一个月都生下一对小兔，而所生下的每一对小兔在出生后的第三个月也都生下一对小兔，
 * 那么由一对兔子开始，满一年时一共可以繁殖成多少对兔子？
 */
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#define MAX 1000

namespace smallData {
    int a[MAX + 5] = {0, 1, 2};
    int f(int n) {
        if (a[n] == 0) {
            a[n] = f(n - 1) + f(n - 2);
        }
        return a[n];
    }
}

/*
 * 整体记忆化+大整数相加
 */
int a[MAX + 5][50] = {{0, 0}, {1, 1}, {1, 2}};
namespace bigData {
    int* f(int n) {
        if (a[n][0] == 0) {
            int *r = f(n - 1);
            int *t = f(n - 2);
            for (int i = 0; i < r[0]; i++) {
                a[n][i + 1] = r[i + 1] + t[i + 1];
            }
            a[n][0] = r[0];
            for (int i = 1; i <= a[n][0]; i++) {
                if (a[n][i] < 10) continue;
                a[n][i + 1] += a[n][i] / 10;
                a[n][i] %= 10;
                a[n][0] += (i == a[n][0]);
            }
        }
        return a[n];
    }
}

int main() {
    int n;
    while (cin >> n) {
        cout << "bigData :";
        if (n == 0) {
            cout << "输入格式错误" << endl;
            continue;
        }
        int *a= bigData::f(n);
        for (int i = a[0]; i >= 1; i--) {
            cout << a[i];
        }
        cout << endl;
    }

    return 0;
}
