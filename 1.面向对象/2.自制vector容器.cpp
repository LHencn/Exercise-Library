/*************************************************************************
	> File Name: 2.自制vector容器.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月29日 星期五 20时34分39秒
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
    public :
        vector() {
            this->data = new T(10);
            this->size = 10;
        }
        int getSize() {
            return size;
        }
        vector(const vector<T> &obj) : size(obj.getSize()), data() {
            
        }
    private :
        int size;
        T *data;
    };
}






int main() {







    return 0;
}
