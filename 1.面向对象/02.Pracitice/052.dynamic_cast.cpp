/*************************************************************************
	> File Name: 052.dynamic_cast.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月26日 星期二 16时00分43秒
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

struct A
{
    virtual ~A() = default;

    virtual void PrintA()
    {
        cout << "A::PrintA" << endl;
    }
};

struct B
{
    virtual ~B() = default;

    virtual void PrintB()
    {
        cout << "B::PrintB" << endl;
    }
};

struct C : A, B
{
    void PrintA()override
    {
        cout << "C::PrintA" << endl;
    }

    void PrintB()override
    {
        cout << "C::PrintB" << endl;
    }
};

int main()
{
    C c;
    A* pa = &c;
    B* pb = &c;

    pa->PrintA();
    pa->A::PrintA();
    pb->PrintB();
    pb->B::PrintB();

    {
        if (pb == dynamic_cast<B *>(pa)) {
            cout << "pb == dynamic_cast<B *>(pa)" << endl;
        } else {
            cout << "is !=" << endl;
        }
    }

    return 0;
}
