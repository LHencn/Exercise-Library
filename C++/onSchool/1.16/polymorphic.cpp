/*************************************************************************
	> File Name: polymorphic.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月16日 星期三 09时30分38秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;


class Parent {
    public :
    virtual void say() {
        cout << "I'm Parent" << endl;
    }
};

class Child : public Parent {
    public :
    void say() {
        cout << "I'm Child" << endl;
    }
};

void How_to_say(Parent *p) { 
    /*多态：希望传入父类指针时调用父类，传入子类指针时调用子类
     * 但编译器为保证安全性，直接调用父类函数，父子兼容
     * 引出关键字virtual
     */
    p->say();
}

int main() {
    Parent p;
    Child c;
    How_to_say(&p);
    How_to_say(&c);
    return 0;
}
