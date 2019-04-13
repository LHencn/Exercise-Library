/*************************************************************************
	> File Name: 6.visitor.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月23日 星期六 09时25分55秒
 ************************************************************************/
//访问者模式
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

class B;
class C;

class A {
public :
    class Visitor {
    public :
        virtual void Visit(B *) = 0;
        virtual void Visit(C *) = 0;
    };
    virtual void test() = 0;
    virtual void Accept(Visitor *vis) = 0;
    virtual ~A() {
        cout << "~A" << endl;
    }
};

class B : public A {
public :
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~B() {
        cout << "~B" << endl;
    }
};

class C : public A {
public :
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~C() {
        cout << "~C" << endl;
    }
};

class coutVisitor : public A::Visitor {
    void Visit(B *) {
        cout << "Class B" << endl;
    }
    void Visit(C *) {
        cout << "Class C" << endl;
    }
};

int main() {
    srand(time(0));
    A *p;
    switch(rand() % 5) {
        case 0: p = new B(); break;
        case 1: p = new C(); break;
    }
    coutVisitor c_vis;
    p->Accept(&c_vis);
    delete p;
    return 0;
}
