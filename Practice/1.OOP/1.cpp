/*************************************************************************
	> File Name: 1.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月14日 星期日 16时10分05秒
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
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {3, 4, 5, 6};
    auto it = find_first_of(begin(a), end(a), begin(b), end(b));
    cout << *it << endl;





    return 0;
}
