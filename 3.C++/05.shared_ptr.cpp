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
        std::shared_ptr<Foo> sh1;   //仅仅声明指针
    }
    std::cout << "************************************\n";
    
    {
        std::cout << "constructor with object\n";
        std::shared_ptr<Foo> sh2(new Foo, D()); //智能指针指向一个Foo的对象
        std::shared_ptr<Foo> sh3(sh2); //调用拷贝构造函数
        std::cout << sh2.use_count() << '\n';
        std::cout << sh3.use_count() << '\n';
    }
    std::cout << "************************************\n";
    
    {
        std::cout << "constructor with object and deleter\n";
        std::shared_ptr<Foo> sh4(new Foo, D());
        std::shared_ptr<Foo> sh5(new Foo, [](auto p) {
            std::cout << "Call delte from lambda...\n";
            delete p;
        });
    }
    std::cout << "************************************\n";
    
    return 0;
}
