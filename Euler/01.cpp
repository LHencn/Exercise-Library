/*************************************************************************
	> File Name: 01.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月08日 星期一 12时50分35秒
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
    int ans3 = (3 + 999) * 333 / 2;
    int ans5 = (5 + 995) * 199 / 2;
    int ans15 = (15 + 1000 / 15 * 15) * (1000 / 15) / 2;
    cout << ans3 + ans5 - ans15 << endl;

    return 0;
}
