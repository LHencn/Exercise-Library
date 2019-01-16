/*************************************************************************
	> File Name: virtual.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月16日 星期三 15时18分52秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Base {
    protected :
    int a;
    public :
    Base(int v1) : a(v1) {}
    bool equal(Base *p) {
        return (this == p);
    }
    int get() {
        return a;
    }
};

class interface1 {
    public :
    virtual void add(int i) = 0;
    virtual void sub(int i) = 0;
};

class interface2 {
    public :
    virtual void mul(int i) = 0;
    virtual void div(int i) = 0;
};

class Derived : public Base, public interface1, public interface2 {
    public :
    Derived(int i) : Base(i) {}
    void add(int i) {
        a += i;
    }
    void sub(int i) {
        a -= i;
    }
    void mul(int i) {
        a *= i;
    }
    void div(int i) {
        if (i != 0) {
            a /= i;
        }
    }
};

int main() {
    Derived d(10);
    Derived *p = &d;
    interface1 *p1 = &d;
    interface2 *p2 = &d;
    if (p->equal(dynamic_cast<Base*>(p1)) && p->equal(dynamic_cast<Base*>(p2))) {
        p1->add(10);
        p1->sub(5);
        p2->mul(10);
        p2->div(15);
    }
    cout << p->get() << endl;
        
    return 0;
}
