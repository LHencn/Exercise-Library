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
class D;
class E;
class F;
class G;

class A {
public :
    class Visitor {
    public :
        virtual void Visit(B *) = 0;
        virtual void Visit(C *) = 0;
        virtual void Visit(D *) = 0;
        virtual void Visit(E *) = 0;
        virtual void Visit(F *) = 0;
        virtual void Visit(G *) = 0;
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

class D : public A {
public :
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~D() {
        cout << "~D" << endl;
    }
};

class E : public A {
public :
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~E() {
        cout << "~E" << endl;
    }
};


class F : public A {
public :
    virtual void test() {}
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~F() {
        cout << "~F" << endl;
    }
};

class coutVisitor : public A::Visitor {
    void Visit(B *) {
        cout << "Class B" << endl;
    }
    void Visit(C *) {
        cout << "Class C" << endl;
    }
    void Visit(D *) {
        cout << "Class D" << endl;
    }
    void Visit(E *) {
        cout << "Class E" << endl;
    }
    void Visit(F *) {
        cout << "Class F" << endl;
    }
    void Visit(G *) {
        cout << "Class G" << endl;
    }
};
/*
void func(A *p) {
    if (dynamic_cast<B *>(p)) { //p is class A
        cout << "class B" << endl;
    } else if (dynamic_cast<C *>(p)){
        cout << "class C" << endl;
    } else if (dynamic_cast<D *>(p)){
        cout << "class D" << endl;
    } else if (dynamic_cast<E *>(p)){
        cout << "class E" << endl;
    } else if (dynamic_cast<F *>(p)){
        cout << "class F" << endl;
    }
}
*/


int main() {
    srand(time(0));
    A *p;
    switch(rand() % 5) {
        case 0: p = new B(); break;
        case 1: p = new C(); break;
        case 2: p = new D(); break;
        case 3: p = new E(); break;
        case 4: p = new F(); break;
    }
/*
    if (dynamic_cast<B *>(p)) { //p is class A
        cout << "class B" << endl;
    } else if (dynamic_cast<C *>(p)){
        cout << "class C" << endl;
    } else if (dynamic_cast<D *>(p)){
        cout << "class D" << endl;
    } else if (dynamic_cast<E *>(p)){
        cout << "class E" << endl;
    } else if (dynamic_cast<F *>(p)){
        cout << "class F" << endl;
    }
    
    func(p);
*/
    coutVisitor c_vis;
    p->Accept(&c_vis);
    delete p;
    return 0;
}
