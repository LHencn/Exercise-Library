/*************************************************************************
	> File Name: test.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月19日 星期六 11时54分17秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <iterator>
#include <initializer_list>

using namespace std; 

void print(int (&arr)[5])
{
    for (auto i : arr)
        cout << i << endl;
}

int main()
{ 
    int odd[5] = {1, 3, 5, 7, 9};
    print(odd);
    return 0;  
}
