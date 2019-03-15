/*************************************************************************
	> File Name: pra.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月15日 星期五 11时38分12秒
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr(10);
    cout << arr.size() << endl;
    int i = 10;
    while (i < 20) {
        arr.push_back(i);//将值插入到动态数组中的末尾
        i++;
    }
    for (int i = 0; i < 20; i++) {
        cout << i << " " << arr[i] << endl;
    }
    cout << arr.size() << endl;

    return 0;
}
