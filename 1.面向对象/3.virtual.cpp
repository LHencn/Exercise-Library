/*************************************************************************
	> File Name: 3.virtual.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月17日 星期日 19时24分31秒
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

class B {
public :
    virtual void test(int x) {
        cout << "my name is B" << endl;
        cout << x << endl;
    }
};

typedef void (*FUNC)(int);

int main() {
    B b;
    int a = 4;
    ((FUNC**)(&b))[0][0];
    return 0;
}
