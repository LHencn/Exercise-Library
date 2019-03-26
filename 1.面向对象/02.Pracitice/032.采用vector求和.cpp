/*************************************************************************
	> File Name: 032.采用vector求和.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月25日 星期一 11时10分07秒
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
    vector<int> a = {1, 2, 3, 4, 5};
    int sum = 0;
    for (auto x : a) {
        sum += x;
    }
    cout << sum << endl;
    return 0;
}
