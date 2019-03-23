/*************************************************************************
	> File Name: 6.多久啦.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月21日 星期四 10时02分23秒
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
        d= 1;
    return d;
}

int main() {
    int y = 1997, m = 11, d = 3, days = 0;
    for (; y < 2019; days++) {
        d = get_next_day(y, m, d);
        m += (d == 1);
        y += ((m == 13) && (m = 1));
    }
    cout << "此时时间" << y << " " << m << " " << d << " " << days << endl;
    m = 1;
    for (; y <= 2019 && m <= 2; days++) {
        d = get_next_day(y, m, d);
        m += (d == 1);
        y += ((m == 13) && (m = 1));
    }

    cout << "此时时间" << y << " " << m << " " << d << " " << days << endl;


    return 0;
}
