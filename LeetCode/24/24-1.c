/*************************************************************************
	> File Name: 24.c
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年10月14日 星期日 09时57分35秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *p = head, *q = head->next, *k = head->next->next;
    head = head->next;
    while (1) {
        q->next = p, p->next = k;
        if (k && k->next) p->next = k->next;
        p = k;
        if (p == NULL || p->next == NULL) break;
        q = p->next, k = q->next;
    }
    return head;
}
