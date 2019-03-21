/*************************************************************************
	> File Name: 2.字符串反转.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月21日 星期四 11时13分18秒
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
    void reserse1(char *s, int n) {
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
    }
};


int main() {
    {
        string s1 = "hello";
        reverse(s1.begin(), s1.end());
        cout << s1 << endl; 
    }
    {
        char s[] = "hello";
        my::reserse1(s, 5);
        cout << s << endl;
    }
    {
        
    }
    


    return 0;
}
