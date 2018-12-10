/*************************************************************************
	> File Name: 19-2.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月14日 星期日 09时37分50秒
 ************************************************************************/

#include<stdio.h>
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode ret, p = &ret, *q = head;
    ret.next = head;
    while (n--) {
        q = q->next;
    }
    while (q) {
        p = p->next;
        q = q->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;
};
