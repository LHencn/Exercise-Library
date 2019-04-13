/*************************************************************************
	> File Name: 2.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月21日 星期一 18时33分32秒
 ************************************************************************/

/* 
 * 创建智能指针:
 * 自己回收开出的内存区域
 * 兼容指针本有的功能
 * 一个指针指向的区域只能有一个指针指向
 * 用一个对象去模拟指针的行为
 * -> 取地址, *取值
 */

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Test {
public :
    Test(int v = 0) {
        i = v;
    }
    int getI() {
        return i;
    }
private :
    int i;
};

class SmartPoint {
public :
    SmartPoint(Test *p = NULL) {
        mp = p;
    }
    SmartPoint(const SmartPoint &obj) { //拷贝构造
        mp = obj.mp;
       const_cast<SmartPoint &>(obj).mp = NULL;
    }
    Test* operator->() {
        /*只能重载成成员函数
         * 函数名、参数固定、不能重载
         */
        return mp;
    }
    Test& operator*() {
        return *mp; // *mp = 8; 一个函数的返回值值是不能当左值使用的
    }
    SmartPoint& operator=(const SmartPoint &obj) {
        if (this != &obj) { //防止自赋值
            delete mp; //
            mp = obj.mp;
            const_cast<SmartPoint &>(obj).mp = NULL;
        }
        return *this;
    }
    ~SmartPoint() {
        cout << "~SmartPoint" << endl;
        delete mp;
    }
private :
    Test *mp;
};

int main() {
    for (int i = 0; i < 5; i++) {
        SmartPoint p = new Test(i);
        /*
         * 运行完该程序p即释放了，但是p指向的内存仍然没有释放
         * 换一种语言，有垃圾回收的功能，比如Java，C#
         * 或者实现垃圾回收的功能
         */
        cout << p->getI() << endl;
    }
    return 0;
}
