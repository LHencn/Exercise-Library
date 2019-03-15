/*************************************************************************
	> File Name: 2.map.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月15日 星期五 14时46分45秒
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
#include <set>
using namespace std;

class A {
public :
    A(int x) : x(x) {}
    bool operator<(const A &obj) const {
        return this->x < obj.x;
    }
    A &operator<<(int &x) {
        x += 1;
        return *this;
    }
    A &operator>>(int &x) {
        x -= 1;
        return *this;
    }
    int x;
};

ostream &operator<<(ostream &out, const A &obj) {
    out << obj.x;
    return  out;
}


int main() {
    A obj(0);
    int a = 1, b = 2, c = 3, d = 4;
    obj << a >> b >> c << d;
    cout << a << b << c << d << endl;
    cout << obj << endl;
    set<int> s;
    s.insert(5);
    s.insert(6);
    s.insert(7);

    return 0;
}
