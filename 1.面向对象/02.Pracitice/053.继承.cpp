/*************************************************************************
	> File Name: 053.继承.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月26日 星期二 16时14分39秒
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

struct A {
    int a;
    virtual ~A() = default;
    void Print() {
        cout << a << endl;
    }
};

struct B {
    int b;
    virtual ~B() = default;
    void Print() {
        cout << b << endl;
    }
};

struct C : A, B {

};

int main() {
    C c;
    c.a = 1;
    c.b = 2;
    B *pb = dynamic_cast<B *>(&c);
    pb->Print();

    return 0;
}
