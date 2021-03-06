/*************************************************************************
	> File Name: 11.responsibity.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月28日 星期四 19时56分05秒
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
#include <functional>
using namespace std;

auto in_range = [](int b, int e) {
    return [=](int x)->bool {
        return (x <= e) && (x >= b);
    };
};

auto AND = [](function<bool(int)> f, function<bool(int)> g) {
    return [=](int x) {
        return (f(x) && g(x));
    };
};

auto OR = [](function<bool(int)> f, function<bool(int)> g) {
    return [=](int x) {
        return (f(x) || g(x));
    };
};

bool is_prime(int x) {
    
    return true;
}

bool is_odd(int x) {
    return true;
}

auto is_digit = in_range('0', '9');
auto is_alpha = OR(in_range('a', '9'), in_range('A', 'Z'));
auto is_valid = AND(is_prime, is_odd);
auto all_digit = [](string str)->bool {
    for (auto x : str) {
        if (!is_digit(x)) return false;
    }
    return true;
};

class A;
class B;
class C;
class D;

class Base {
public:
    virtual bool test(string &str) = 0;
    virtual void do_something() = 0;

private:
    Base *next;
    static Base *head;
    static Base *getLink() {
        if (Base::head) return Base::head;
        head = new A;
        head->next = new B;
        head->next->next = new C;
        head->next->next->next = new D;
    }
};

class A : public Base {
public:
    bool test(string &str) {
        if (str.size() = 1 && str = '.') return true;
        return false;
    }
    void do_something() {
        cout << 1 << endl;
    }
};

class B : public Base {
public:
    bool test(string &str) {
        if (str.size() = 1 && str = '.') return true;
        return false;
    }
    void do_something() {
        cout << 1 << endl;
    }
};

Base *getLink() {
    if (Base::head) return Base::head;
    Base::head = new A;
    Base::head = new B;
    Base::head = new C;
    Base::head = new D;
}

void Base::run(string &str) {
    Base *p = getLink();
    while (p && p->test(str) == false)  {
        p = p->next;
    }
    if (p == nullptr) return ;
    p->do_something();
    return ;
}

int main() {
    string str;
    cin >> str;
    if (str.size() == 1 && str == ".") {
        cout << 1 << endl;
    } else if (all_diit(str)) {
        cout << 

    }
    



    return 0;
}
