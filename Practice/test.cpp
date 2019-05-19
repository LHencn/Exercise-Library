/*************************************************************************
	> File Name: test.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年04月25日 星期四 21时50分30秒
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
    
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
 
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> arr;
        ListNode *p = head->next, *q, *temp;
        q = NULL;
        while (p) {
            temp = p->next;
            p->next = q;
            q = p;
            p = temp;
        }
        while (q) {
            arr.push_back(q->val);
            q = q->next;
        }
        return arr;
    }
};
