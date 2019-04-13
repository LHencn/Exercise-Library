/*************************************************************************
	> File Name: 6.1.visitor.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月31日 星期日 11时02分09秒
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

class B;
class C;

class A {
public :
    class Visitor {
    public :
        virtual void Visit(B *) = 0;
        virtual void Visit(C *) = 0;
    };
    virtual void Accept(Visitor *vis) = 0;
    virtual ~A() {
        cout << "~A" << endl;
    }
};

class B : public A {
public :
    virtual void Accept(Visitor *vis) {
        vis->Visit(this);
    }
    ~B() {
        cout << "~B" << endl;
    }
};
