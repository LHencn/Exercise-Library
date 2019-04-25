/*************************************************************************
	> File Name: 01.insertion_sort.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月20日 星期六 10时16分11秒
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

template <class T>
void foo(const T& t) {
    typename T::bar *p;
}

struct Bar {
    typedef int bar;
};

template <class T, class U>
class vector {

    int data;
    T bar;
};

template <typename T>
class Base {
public:
    typedef Bar Bard;
    T bar;
};

template <typename T>
class Derived : public Base<T>::Bard {
public:
    Derived(int x) : Base<T>::bar(x), data(10) {}
private:
    int data;
};



int main() {
    {  
        Bar x;
        foo(x);
    }

    {
        Derived<int> derived(5);
    }
  
    return 0;
}
