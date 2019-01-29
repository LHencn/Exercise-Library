/*************************************************************************
	> File Name: 19.delete_node.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2019年01月29日 星期二 14时32分58秒
 ************************************************************************/

#include<stdio.h>
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = 0;
    struct ListNode *p = head;
    while (!p) {
        len++;
        p = p->next;
    }
    p = head;
    for (int i = 0; i < len - n - 1; i++) {
        p = p->next;
    }
    struct ListNode *q = p->next;
    p = q->next;
    free(q);
    head = p;
    return head;
}
