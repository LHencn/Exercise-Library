/*************************************************************************
	> File Name: 051.dynamic_cast.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月26日 星期二 09时44分11秒
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
#include <string.h>
#include <memory>
using namespace std;

struct Animal {
public :
    Animal() {
        cout << "Animal()" << endl;
    }
    virtual void setName(string name) = 0;
    virtual void Print() {
        cout << "A::Print" << endl;
    }
    virtual ~Animal() {
        cout << "~Animal()" << endl;
    }
protected :
    string name;
};

struct B {
public:
    B() {
        cout << "B()" << endl;
    }
    virtual void Print() {
        cout << "B::Print" << endl;
    }
    virtual ~B() {
        cout << "~B()" << endl;
    }
};

struct Cat : B, Animal {
public :
    Cat() {
        cout << "Cat()" << endl;
    }
    void setName(string name) {
        this->name = name;
    }
    ~Cat() {
        cout << "~Cat()" << endl;
    }
};

class Dog : public Animal {
public :
    Dog() {
        cout << "Dog()" << endl;
    }
    void setName(string name) {
        this->name = name;
    }
    ~Dog() {
        cout << "~Dog()" << endl;
    }
};

int main() {

    {
        Cat c;
        Animal *pa = &c;
        B *pb = &c;
        //B *pb = dynamic_cast<B *>(pa);
        if (pb == dynamic_cast<B *>(pa)) {
            cout << "pb == dynamic_cast<B *>(pa)" << endl;
        } else {
            cout << "!=" << endl;
        }
        
    }

    {//dynamic_cast可以将子类指针转为指向父类

        cout << "*******************************" << endl;
        cout << "子类指针转为指向父类" << endl;
        Cat *cat = new Cat;
        Animal *it = dynamic_cast<Animal *>(cat);
        if (it == nullptr) {
            cout << "nullptr" << endl;
        } else {
            cout << "It is not nullptr" << endl;
        }
    }

    {//dynamic_cast同级交叉转换时会返回一个空指针

        cout << "*******************************" << endl;
        cout << "同级交叉转换" << endl;
        Dog *dog = new Dog;
        Cat *it = dynamic_cast<Cat *>(dog);
        if (it == nullptr) {
            cout << "nullptr" << endl;
        } else {
            cout << "It is not nullptr" << endl;
        }
    }
   
    /*
    {//dynamic_cast可以将父类指针转为指向子类
     
        cout << "*******************************" << endl;
        cout << "父类指针转为指向子类" << endl;
        Animal *animal = new Animal;
        Cat *it = dynamic_cast<Cat *>(animal);
        if (it == nullptr) {
            cout << "nullptr" << endl;
        } else {
            cout << "It is not nullptr" << endl;
        }
    }*/

    
    return 0;
}
