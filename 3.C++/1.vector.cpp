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

int main() {
    {
        vector<int> a(10);
        vector<int> b(10, 0);
        vector<int> c = {1, 2, 3, 4, 5};
        int x = c[2];
        c[3] = x;
    }

    {
        int a[] = {1, 2, 3, 4, 5};
        int sum = 0;
        for (int i = 0; i < sizeof(a) / sizeof(*a); i++) {
            sum += a[i];
        }
        cout << sum << endl;
    }

    {
        int a[] = {1, 2, 3, 4, 5};
        int sum = 0;
        for (auto x : a) {
            sum += x;
        }
        cout << sum << endl;
    }
    
    {
        int a[] = {1, 2, 3, 4, 5};
        int b[] = {3, 4, 5, 6, 7};
        int *it = nullptr;
        for (int i = 0; i < sizeof(a) / sizeof(*a); i++) {
            for (int j = 0; j < sizeof(b) / sizeof(*b); j++) {
                if (a[i] == b[j]) {
                    it = &a[i];
                    break;
                }
            }
        }
        bool found = (it != nullptr);
        cout << "found = " << found << " *it = " << *it << endl;
    }

    {
        vector<int> a = {1, 2, 3, 4, 5};
        vector<int> b = {3, 4, 5, 6, 7};
        auto it = find_first_of(begin(a), end(a), begin(b), end(b));
        bool found = (it != end(a));
        cout << "found = " << found << " *it = " << *it << endl;
    }
    
    {
        
    }
    return 0;
}
