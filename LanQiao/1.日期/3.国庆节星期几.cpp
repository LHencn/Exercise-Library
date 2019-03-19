/*************************************************************************
	> File Name: 3.国庆节星期几.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月19日 星期二 11时15分32秒
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

typedef struct Date {
    int y, m, d, w;
}Date;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int get_next_day(int y, int m, int d, int &w) {
    d += 1;
    if (d > (month[m] + (m == 2 && is_leap(y))))
        d = 1;
    w += 1;
    if (w > 7)
        w = 1;
    return d;
}

int main() {
    int y = 1949, m = 10, d = 1, w = 6, cnt = 0;
    for (;y <= 2012;) {
        d = get_next_day(y, m, d, w);
        m += (d == 1);
        y += ((m == 13) && (m = 1));
        if (m == 10 && d == 1 && w == 7) {
            cout << y << "-" << m << "-" << d << "-" << w << endl;
        }
    }
    cout << cnt << endl;
    return 0;
}
