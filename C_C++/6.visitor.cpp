/*************************************************************************
	> File Name: 6.visitor.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月23日 星期六 09时25分55秒
 ************************************************************************/

//如何判断一个指针是指向父类还是子类的
//当我们强制转换时析构函数就变成了一个虚函数

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
    virtual void test() = 0;
    virtual ~A() {
        cout << "~A" << endl;
    }
};

class B : public A {
public :
    virtual void test() {}
    ~B() {
        cout << "~B" << endl;
    }
};

class C : public A {
public :
    virtual void test() {}
    ~C() {
        cout << "~C" << endl;
    }
};

int main() {
    srand(time(0));
    A *p;
    if (rand() % 2) {
        p = new B();
    } else {
        p = new C();
    }
    if (dynamic_cast<B *>(p)) { //p is class A
        cout << "class B" << endl;
    } else {
        cout << "class C" << endl;
    }
    delete p;
    return 0;
}
