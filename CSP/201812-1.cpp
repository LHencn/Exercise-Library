/*************************************************************************
	> File Name: 201812-1.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月17日 星期日 09时36分57秒
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
    int r, g, y, n, k, t, ans = 0;
    cin >> r >> y >> g;
    cin >> n;
    while (n--) {
        cin >> k >> t;
        switch(k) {
            case 0: {
                ans += t;
                break;
            }
            case 1: {
                ans += t;
                break;
            }
            case 2: {
                ans += (t + r);
                break;
            }
            case 3: {
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
