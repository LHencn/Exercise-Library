/*************************************************************************
	> File Name: template.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月16日 星期三 15时58分54秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#define SWAP(t, a, b) {\
    t (temp) = (a);\
    (a) = (b);\
    (b) = (temp);\
}

void my_swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void my_swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void my_swap(string &s1, string &s2) {
    string temp = s1; //拷贝构造函数
    s1 = s2; //重载的等号
    s2 = temp;
}

template <typename T>
void my_swap1(T &a, T &b) {
    T temp = a; //Test的私有拷贝构造函数，无法引用
    a = b;
    b = temp;
}

template <typename T>
void my_sort(T *a, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (a[i] > a[j]) {
                my_swap1(a[i], a[j]);
            }
        }
    }
}

class Test {
    public:
        Test(const Test &t) {
            
        }
    public :
        Test() { 
            
        }
};

template <typename T>
void print(T *a, int len) {
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[5] = {3, 2, 1, 4, 6};
    double b[5] = {3.1, 4.2, 1.7, 2.3, 5.4};
    string s[5] = {"c", "java", "C#", "python", "C++"};
    print(a, 5);
    my_sort(a, 5);
    print(a, 5);
    cout << endl;
    print(b, 5);
    my_sort(b, 5);
    print(b, 5);

    print(s, 5);
    my_sort(s, 5);
    print(s, 5);
    /*
    string s1 = "wrf", s2 = "cxh";
    int a = 10, b = 20;
    double c = 2.1, d = 3.4;
    SWAP(int, a, b);
    SWAP(double, c, d);
    SWAP(string, s1, s2);
    my_swap(a, b);
    my_swap(c, d);
    my_swap(s1, s2);
    cout << "a = "<< a << " b = " << b << endl;
    cout << "c = "<< c << " d = " << d << endl;
    cout << "s1 = " << s1 << " s2 = " << s2 << endl;
    Test t1, t2;
    my_swap1(t1, t2);
    */
    return 0;
}
