/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月13日 星期六 11时26分17秒
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
    template <typename T>
    class vector {
    public:
        vector() {
            this->data = new T[10];
            this->size = 10;
        }
        vector(const vector<T> &arr) : data(nullptr), size(0) {
            if (this->data) {
                delete[] this->data;
            } 
            this->size = arr.size;
            for (int i = 0; i < this->size; i++) {
                new (this->data + i) T(arr.data + i);
            }
        }
        T &operator[](int ind) { 
            //为什么要返回引用,因为需要更改其中的值
            return this->data[ind];
        }



    private:
        T *data;
        int size;
    };

}


int main() {
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
