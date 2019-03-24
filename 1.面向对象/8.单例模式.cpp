/*************************************************************************
	> File Name: 8.单例模式.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月24日 星期日 19时27分53秒
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
using namespace std;

class SingleClass {
public :
    int getX() { return x; }
    static SingleClass *get() {
        if (SingleClass::obj == nullptr) {
            obj = new SingleClass();
        }
        return obj;
    }
private :
    int x;
    static SingleClass *obj;
    SingleClass() { x = 123; }
    SingleClass(const SingleClass &obj) {}
};

SingleClass *SingleClass::obj = nullptr;

int main() {
    SingleClass *p1 = SingleClass::get();
    SingleClass *p2 = SingleClass::get();
    cout << p1 << " " << p2 << endl;
    cout << p1->getX() << endl;


    return 0;
}
