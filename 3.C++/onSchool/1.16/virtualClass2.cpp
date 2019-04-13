/*************************************************************************
	> File Name: virtualClass2.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月16日 星期三 14时51分04秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class BaseA {
    public :
        virtual void funcA() { 
            //虚函数指针的大小为8字节，存地址
            cout << "BaseA::funcA" << endl;
        }
};

class BaseB {
    public :
        virtual void funcB() {
            cout << "BaseB::funcB" << endl;
        }
};

class Derived : public BaseA, public BaseB {  };

int main() {
    cout << sizeof(Derived) << endl;
    Derived d;
    BaseA *p1 = &d;
    BaseB *p2 = &d;
    p1->funcA(); //BaseA
    p2->funcB(); //BaseB 
    BaseB *pb = (BaseB *)p1;
    pb->funcB();
    BaseB *pbb = dynamic_cast<BaseB *>(p1);
    pbb->funcB();
    return 0;
}
