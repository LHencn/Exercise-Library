/*************************************************************************
	> File Name: 031.传统数组求和.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月25日 星期一 11时08分43秒
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

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i < sizeof(a) / sizeof(*a); i++) {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}
