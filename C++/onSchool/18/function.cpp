/*************************************************************************
	> File Name: 1.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月18日 星期五 09时11分50秒
 ************************************************************************/

/*
 * 普通函数、模板函数和变参函数同时存在的调用顺序
 * 调用顺序：普通函数、模板函数、变参函数
 * 模板函数、普通函数、变参函数可以构成重载关系
 * 优先调用普通函数，可能是因为普通函数编译一次，更快
 */
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void add(int a, int b) {
    cout << "void add(int a, int b)" << endl;
    //cout << a + b << endl;
}

void add(int a) {
    cout << "add(int a)" << endl;
}
template <typename T>
void add(T a, T b) {
    cout << "void add(T a, T b)" << endl;
    //cout << a + b << endl;
}

void add(...) {
    cout << "void add(...)" << endl;
}

int main() {
    add(1, 3); //add(int a, int b);
    add(3.4, 4.3); //模板;
    add(3); //add(int a);
    add<>(1, 3); //模板;
    return 0;
}
