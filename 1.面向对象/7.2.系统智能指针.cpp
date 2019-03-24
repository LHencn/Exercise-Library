/*************************************************************************
	> File Name: 7.智能指针.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月24日 星期日 14时23分52秒
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
#include <memory>
using namespace std;

class A {
public: 
    A() {x = 456;}
    virtual int getX() {return this->x; }
    int x;
    virtual ~A() {
        cout << "Class A" << endl;
    }
};

class B : public A {
public :
    B() {
        x = 789;
        y = 689;
    }
    virtual int getX() {return this->x; }
    virtual int getY() {return this->y; }
    int x, y;
    ~B() {
        cout << "Class B" << endl;
    }
};

template<typename T>
class my_shared {
public :
    my_shared() : p(nullptr) {}
    my_shared(T *p) : p(p) {
        mp[reinterpret_cast<T *>(p)] += 1;
    }
    int use_count() {
        return mp[reinterpret_cast<T *>(p)];
    }
    T *get() { return p; }
    T &operator*() { return *p; }
    T *operator->() { return p; }
    ~my_shared() {
        if (p != nullptr) {
            mp[reinterpret_cast<T *>(p)] += 1;
            if (mp[reinterpret_cast<T *>(p)]) {
                delete p;
            }
            p = nullptr;
        }
    }
private :
    T *p;
    static map<T *, int> mp;
};

void func() {
    my_shared<A> p(new B);
    cout << p->getX() << endl;
    A *q = p.get();
    //shared_ptr<A> q2(q);
    cout << p->getX() << endl;
}

int main() {
    func();
    cout << "func end" << endl;
    return 0;
}
