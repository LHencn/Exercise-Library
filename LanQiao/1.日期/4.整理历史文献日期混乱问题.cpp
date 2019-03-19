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
    int y, m, d;
}Data;

void con(int y, int m, int d, Data &data) {
    if (y >= 60) 
        y += 1900;
    else 
        y += 2000;
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

int main() {
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);
    Data arr[3];
    con(y, m, d, arr[0]);
    con(d, y, m, arr[1]);
    con(d, m, y, arr[2]);
    sort(arr, arr + 3, cmp);
    for (int i = 0; i < 3; i++) {
        printf("%d-%02d-%02d\n", arr[i].y, arr[i].m, arr[i].d);
        
    }
    return 0;
}
