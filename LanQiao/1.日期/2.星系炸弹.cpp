/*************************************************************************
	> File Name: 2.星系炸弹.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月19日 星期二 11时01分02秒
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
    d++;
    if (d > (month[m] + (m == 2 && is_leap(y)))) 
        d = 1;
    return d;
}

int main() {
    int y = 2014, m = 11, d = 9;
    int days = 1000;
    while (days--) {
        d = get_next_day(y, m, d);
        m += (d == 1);
        y += ((m == 13) && (m = 1));
    }
    cout << y << "-" << m << "-" << d << endl;
    return 0;
}
