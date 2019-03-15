/*************************************************************************
	> File Name: 1.pra.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月15日 星期五 14时23分23秒
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
#include <set>
using namespace std;

int main() {
    srand(time(0));
    map<string, int> arr;
    arr["hello"] = 1;
    arr["world"] = 2;
    arr["I AM YOU"] = 3;
    for (auto i : arr) {
        cout << i.first << " " << i.second << endl;
    }
    string temp;
    cin >> temp;
    if (arr.find(temp) == arr.end()) {
        cout << "not" << endl;
    }
    cout << temp << " " << arr[temp] << endl;

    set<int> ss;
    int n;
    while ((cin >> n) && n) {
        ss.insert(n);
    }
    for (auto x : ss) {
        cout << x << " ";
    }
    cout << endl;
    

    return 0;
}
