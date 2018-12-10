/*************************************************************************
	> File Name: 19.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月14日 星期日 09时32分04秒
 ************************************************************************/

#include<stdio.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = 0;
    struct ListNode *p = head, ret;
    ret.next = head;
    while (p) {
        p = p->next;
        len++;
    }
    p = &ret;
    len -= n;
    while (len--) {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;
}
