/*************************************************************************
	> File Name: 2.string.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月13日 星期六 15时08分21秒
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
        string str1("the usage of find can you use it");
        string str2("the");
        cout << str1.find(str2) << endl;
        auto flag = str1.find(str2, 5);
        bool found = (flag == string::npos);
        cout << str1.find(str2, 5) << " found = " << found << endl;
        cout << str1.find("usage") << endl;
        cout << str1.find("o") << endl;
        cout << str1.find("of big", 2, 2) << endl;
        cout << "********************************" << endl;
    }
    
    {
        std::string str("the of");
        string str2("the");
        str.find(str2);
        cout << "********************************" << endl;
    }
    
    {
        vector<int> vec = {1, 3, 6};
        auto ite = find(vec.begin(), vec.end(), 2);
        cout << ite << endl;
	    vec.insert(ite,2,77);  //迭代器标记的位置前，插入数据；
        for (auto x : vec) {
            cout << x << " ";
        }
        cout << endl;
	    cout<<*ite<<endl;  //会崩溃，因为迭代器在使用后就释放了，*ite的时候就找不到它的地址了；
        cout << "********************************" << endl;
    }
    



    return 0;
}
