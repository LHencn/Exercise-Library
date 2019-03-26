/*************************************************************************
	> File Name: 02.传统数组倒序.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月25日 星期一 11时01分21秒
 ************************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;

int compare(const void* x, const void* y)
{
   return *reinterpret_cast<const int*>(y) - *reinterpret_cast<const int*>(x);
}

int main()
{
    int a[] = { 2, 4, 5, 3, 1 };
    qsort(
        a,
        sizeof(a) / sizeof(*a),
        sizeof(*a),
        &compare
        );
    for (auto x : a) {
        cout << x << (x == *begin(a) ? "" : " ");
    }
    cout << endl;
    return 0;
}

