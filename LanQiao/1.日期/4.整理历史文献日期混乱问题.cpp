/*************************************************************************
	> File Name: 4.整理历史文献日期混乱问题.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月19日 星期二 11时32分38秒
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

typedef struct Data {
    int y, m, d, flag;
}Data;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

void con(int y, int m, int d, Data &data) {
    if (y >= 60) 
        y += 1900;
    else 
        y += 2000;
    data.flag = 0;
    if (d <= (month[m] + (m == 2 && is_leap(y))))
        data.flag = 1;
    if (m != 2)
    data.y = y;
    data.m = m;
    data.d = d;
    return ;
}

bool cmp(Data &a, Data &b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

int operator==(Data &a, Data &b) {
    if (a.y == b.y && a.m == b.m && a.d == b.d)
        return 1;
    return 0;
}

int main() {
    int y, m, d;
    while (scanf("%d/%d/%d", &y, &m, &d) != EOF) {
    Data arr[3];
    con(y, m, d, arr[0]);
    con(d, y, m, arr[1]);
    con(d, m, y, arr[2]);
    sort(arr, arr + 3, cmp);
    for (int i = 0; i < 3; i++) {
        if (i == 1 && (arr[1] == arr[0]))
            break;
        if (i == 2 && (arr[2] == arr[1]))
            break;
        arr[i].flag && printf("%d-%02d-%02d\n", arr[i].y, arr[i].m, arr[i].d);
        
    }
    }
    return 0;
}
