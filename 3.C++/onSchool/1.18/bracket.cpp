/*************************************************************************
	> File Name: bracket.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月18日 星期五 20时14分38秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Fib {
public :
    Fib() {
        a0 = 0;
        a1 = 1;
    }
    Fib(int n) {
        a0 = 0;
        a1 = 1;
        for (int i = 2; i <= n; i++) {
            int t = a1;
            a1 = a0 + a1;
            a0 = t;
        }
    }
    int operator()() { //每次调用时用该函数
        int ret = a1;
        a1 = a1 + a0;
        a0 = ret;
        return ret;
    }
    int operator()(int n) {
        a0 = 0;
        a1 = 1;
        for (int i = 2; i <= n; i++) {
            int t = a1;
            a1 = a0 + a1;
            a0 = t;
        }
    }
private :
    int a0;
    int a1;
};

int main() {
    Fib fib;
    for (int i = 0; i < 10; i++) {
        cout << fib() << endl;
    }
    cout << fib(10) << endl;
    Fib fib1(10);
    for (int i = 0; i < 10; i++) {
        cout << fib1() << endl;
    }
    return 0;
}
