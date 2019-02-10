/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode ret;
    ret.next = head;
    struct ListNode *p = &ret;
    head = p;
    struct ListNode *temp;
    while (p->next  != NULL && p->next->next != NULL) {
        temp = p->next->next;
        p->next->next = temp->next;
        temp->next = p->next;
        p->next = temp;
        p = p->next->next;
    }
    return head->next;
}
