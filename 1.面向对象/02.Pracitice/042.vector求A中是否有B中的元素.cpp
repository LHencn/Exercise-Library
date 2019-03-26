/*************************************************************************
	> File Name: 042.vector求A中是否有B中的元素.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月25日 星期一 11时24分25秒
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
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {4, 5, 5};
    auto it = find_first_of(begin(a), end(a), begin(b), end(b));
    cout << (it != end(a)) << endl;

    return 0;
}
