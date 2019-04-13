/*************************************************************************
	> File Name: 4.size_t.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月13日 星期六 17时31分55秒
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
    const std::size_t N = 10;
    int *a = new int[N];
    for (std::size_t n = 0; n < N; n++) 
        a[n] = n;
    for (std::size_t n = N; n-- > 0;)
        std::cout << a[n] << " ";
    delete[] a;

    return 0;
}
