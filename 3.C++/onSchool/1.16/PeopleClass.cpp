/*************************************************************************
	> File Name: PeopleClass.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月16日 星期三 09时17分50秒
 ************************************************************************/

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class People {
    private :
    string name;
    int age;
    public :
    People(string s1, int v1) : name(s1), age(v1) {}
    void print() {
        cout << name << " " << age << endl;
    }
};

class Teacher : virtual public People {
    public :
    Teacher(string s1, int v1) : People(s1, v1) {}
};

class Student : virtual public People {
    public :
    Student(string s1, int v1) : People(s1, v1) {}
};

class Doctor : public Teacher, public Student {
    public :
    Doctor(string s1, int v1) : Teacher(s1 + "1", v1), Student(s1, v1), People(s1, v1) {}
};


