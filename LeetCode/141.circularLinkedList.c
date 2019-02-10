/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
   if(head == NULL) return false;
    struct ListNode *p = head, *q = head->next;
    while (q && q->next) {
        p = p->next;//慢指针
        q = q->next->next;//快指针
        if (p == q) return true;
    }
    return false;
}
