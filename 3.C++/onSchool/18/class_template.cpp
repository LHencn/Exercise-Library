/*************************************************************************
	> File Name: class_template.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月18日 星期五 09时35分28秒
 ************************************************************************/

/*
 * 类中模板的使用、对象定义的方法
 */
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
template <typename T>
class Test {
public :
    Test(T v) {
        a = v; //赋值符号重载
    }
    T getA() {
        return a;
    }
    T sub(T b) {
        return a - b;
    }
    friend string operator-(const string &s1, const string &s2);
private :
    T a;
};

template <typename T>
T operator-(const T &s1, const T &s2) {
    return "0";
}


int main() {
    Test<int> t(5); //类模板定义方法
    cout << "t.getA() = " << t.getA() << endl;
    string s1 = "wrf";
    string s2 = "haizeix";
    Test<string> t1(s1);
    /*
     * 调用顺序：把T换成string，调用Test的构造函数，a = v;过程调用String中的operater=
     */
    cout << t1.getA() << endl;
    cout << t1.sub(s2) << endl;
    return 0;
}
