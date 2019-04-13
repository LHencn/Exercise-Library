/*************************************************************************
	> File Name: 05.shared_ptr.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月13日 星期六 17时59分23秒
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

struct Foo {
    Foo() { std::cout << "Foo...\n"; }
    ~Foo() { std::cout << "~Foo...\n"; }
};

struct D {
    void operator()(Foo* p) const {
        std::cout << "Call from function object...\n";
        delete p;
    }
};

int main() {
    {
        std::cout << "constructor with no managed object\n";
        std::shared_ptr<Foo> sh1;    
        std::cout << "************************************\n";
    }
    
    {
        std::cout << "constructor with object\n";
        std::shared_ptr<Foo> sh2(new Foo);
        std::shared_ptr<Foo> sh3(sh2);
        std::cout << sh2.use_count() << '\n';
        std::cout << sh3.use_count() << '\n';
        std::cout << "************************************\n";
    }

    




    return 0;
}
