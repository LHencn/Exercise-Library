/*************************************************************************
	> File Name: 1.高斯日记.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月19日 星期二 10时24分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>
using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int get_next_day(int y, int m, int d) {
    d += 1;
    if (d > (month[m] + (m == 2 && is_leap(y))))
        d = 1;
    return d;
}

int main() {
    int y = 1777, m = 4, d = 30;
    int days = 8113;
    days--;
    while (days--) {
        d = get_next_day(y, m, d);
        m += (d == 1);
        y += ((m == 13) && (m = 1));
    }
    cout << y << "-" << m << "-" << d << endl;
    return 0;
}
