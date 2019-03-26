/*************************************************************************
	> File Name: 041.传统A中是否有B中元素.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月25日 星期一 11时12分20秒
 ************************************************************************/

/*
 *错误实例：形参中的数组为指针，所占字节为8字节
 */

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

bool is_have(int *a, int *b) {
    for (int i = 0; i < sizeof(a) / sizeof(*a); i++) {
        for (int j = 0; j < sizeof(b) / sizeof(*b); j++) {
            cout << a[i] << " " << b[i] << endl;
            if (a[i] == b[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {3, 4, 5, 8};
    cout << is_have(a, b) << endl;
    
    return 0;
}
