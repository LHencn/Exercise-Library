/*************************************************************************
	> File Name: 3._质数筛.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年03月08日 星期五 15时36分40秒
 ************************************************************************/

 #include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int n;
    int k;
    int numbers[1000001];
    int m;
    int i;

    int first, last, mid;
    // 反复读入数字和查找数字的数量
    while (scanf("%d %d", &n, &k) != EOF) {

        // 读入给定的数字
        for (i = 0; i < n; i++) {
            scanf("%d", &numbers[i]);
        }

        for (int j = 0; j < k; j++) {
            // 读入待查找的数字，
            scanf("%d", &m);

            // 请在下面完成查找读入数字的功能
            int flag = 0;
			first = 0, last = n - 1;
            while (first <= last) {
                mid = (first + last) / 2;
                if (numbers[mid] == m) {
                    flag = 1;
                    if (j != k - 1) {
                        cout << mid + 1 << " ";
                    } else {
                        cout << mid + 1 << endl;
                    }
                    break;
                } else if (numbers[mid] < m) {
                    first = mid + 1;
                } else {
                    last = mid - 1;
                }
            }
            if (flag == 0) {
                if (j != k - 1) {
                    cout << 0 << " ";
                } else {
                    cout << 0 << endl;
                }
            }
        }
    }
    return 0;
}
