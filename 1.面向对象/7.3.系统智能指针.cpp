/*************************************************************************
	> File Name: 7.3.系统智能指针.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月24日 星期日 15时39分32秒
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

namespace my {
    template<typename T>
    class shared_ptr {
    public :
        shared_ptr() : p(nullptr), cnt(nullptr) {}
        shared_ptr(T *p) : p(p), cnt(nullptr) {

        }
        shared_ptr(const shared_ptr<T> &obj) : p(p) {}
        shared_ptr(shared_ptr<T> &&obj) : p(p) {obj.p = nullptr; }
        T &operator*() { return *p; }
        T *operator->() { return p; }
        size_t &use_count() {
            return *cnt;
        }
        T *get() {
            return p;
        }
        template<typename U>
        shared_ptr<T> &operator=(shared_ptr<U> &obj) {
            sub_one();
            p = obj.get();
            cnt = &
        }
        ~shared_ptr() {
            sub_one();
        }
    private :
        void sub_one() {
            if (p == nullptr) return ;
            (*cnt) -= 1;
            if ((*cnt) == 0) {
                delete p;
                delete cnt;
                cnt = nullptr;
            }
            p = nullptr;
        }
        T *p;
        size_t *cnt;
    };
};


class A {
public :
    A() {}
    virtual ~A() {
        cout << "Class A" << endl;
    }
};


