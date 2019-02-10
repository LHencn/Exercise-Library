/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *p = head->next, *q = head, *temp;
    q->next = NULL;
    while (p->next) {
        temp = p->next;
        p->next = q;
        q = p;
        p = temp;
    }
    p->next = q;
    return p;
}
