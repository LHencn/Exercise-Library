/*************************************************************************
	> File Name: 06.template.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月13日 星期六 20时12分26秒
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

void g(double) { std::cout << "g(double)\n"; }


template<class T>
struct S {
    void f() const {
        g(1);
    }
};

void g(int) { std::cout << "g(int)\n"; }

template<typename T>
struct X : B<T> {
    typename T::A* pa;
    void f(B<T>* pb) {
        static int i = B<T>::i;
        pb->j++;
    }
};





int main() {
    g(1);
    S<int> s;
    s.f();

    return 0;
}
