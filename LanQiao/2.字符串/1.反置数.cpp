/*************************************************************************
	> File Name: 1.反置数.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月21日 星期四 10时46分20秒
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
#include <string.h>
using namespace std;

int reverse(int d) {
    char s[20];
    int res = 0;
    itoa(d, s, 10);
    int len = strlen(s);

}

int main() {
    int x, y;
    cin >> x >> y;
    cout << reverse(x) + reverse(y) << endl;
    return 0;
}
