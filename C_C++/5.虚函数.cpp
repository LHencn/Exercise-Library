/*************************************************************************
	> File Name: 4.虚函数.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月21日 星期四 18时30分32秒
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

class A {
public :
    void test() {
        cout << "class A" << endl;
    }
};

class B : public A {
public :
    void test() {
        cout << "class B" << endl;
    }
};

int main() {
    srand(time(0));
    A *arr[10];
    for (int i = 0; i < 10; i++) {
        if (rand() % 2) {
            arr[i] = new A();
        } else {
            arr[i] = new B();
        }
    }
    for (int i = 0; i < 10; i++) {
        arr[i]->test();
    }
    return 0;
}
