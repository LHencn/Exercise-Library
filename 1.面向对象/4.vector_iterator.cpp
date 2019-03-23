/*************************************************************************
	> File Name: 4.vector_iterator.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月19日 星期二 20时11分24秒
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
    class vector_iterator {
    public :
        vector_iterator() : p(nullptr) {}
        vector_iterator(T *p) : p(p) {}
        vector_iterator(const vector_iterator<T> &obj) : p(obj.p) {}
        vector_iterator(vector_iterator<T> &&obj) : p(obj.p) {}
        bool operator!=(const vector_iterator<T> &obj) {
            return this->p != obj.p;
        }
        bool operator==(const vector_iterator<T> &obj) {
            return this->p == obj.p;
        }
        T &operator*() {
            return *p;
        }
        vector_iterator<T> &operator++() { //前加加返回一个左值
            p++;
            return *this;
        }
        vector_iterator<T> oerator++(int x) { //后加加返回一个右值
            vector_iterator<T> ret(*this);
            p++;
            return *ret;
        }
    private :
        T *p;
    };
    class vector {
    public :
        typedef vector_iterator<T> iterator;//最有价值
        vector() {
            this->data = nullptr;
            this->size = 10;
            this->length = 0;
        }
        vector(const vector<T> &arr) : data(nullptr), size(0), length(0) {
            clear();
            this->data = new T[arr.size];
            for (int i = 0; i < arr.length; i++) {
                new(this->data + i) T(arr[i]);
            }
            this->size = arr.size;
            this->length = arr.length;
        }
        vector(vector<T> &&arr) : 
            data(arr.data), 
            size(arr.size),
            length(arr.length) 
        {
            arr.data = nullptr;
            arr.size = 0;
            arr.length = 0;
        }
        T &operator[](size_t ind) {
            return this->data[ind];
        }
        void expand() {
            int new_size = size * 2 + 1;
            int raw_length = length;
            T *p_arr = new T[new_size];
            for (int i = 0; i < this->length; i++) {
                new(p_arr + i) T(std::move(data[i]));
            }
            clear();
            data = p_arr;
            size = new_size;
            length = raw_length;
            return ;
        }
        iterator &&begin() {
            return iterator(this->data);
        }
        iterator &&end() {
            return iterator(this->data + this->length);
        }
        void push_back(const T &obj) {
            if (this->length >= this->size) {
                this->expand();
            }
            new(this->data + this->length++) T(obj);
            this->length += 1;
            return ;
        } 
        void clear() {
            if (this->data != nullptr) {
                delete[] this->data;
            }
            this->data = nullptr;
            this->size = 0;
            this->length = 0;

        }
        ~vector() {
            if (this->data != nullptr)
                delete[] this->data;
            this->data = nullptr;
            this->size = 0;
            this->length = 0;
        }
    private :
        T *data;
        size_t size, length;
    };

    void test() {
        vector<int> arr;
        for (int i = 0; i < 10; i++) {
            arr.push_back(i);
        }
        for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++) {
            cout << *iter << endl;
        }
        return ;
    }
};


int main() {
    


    return 0;
}
