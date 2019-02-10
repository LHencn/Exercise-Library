/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode ret;
    ret.next = head;
    struct ListNode *p = ret.next, *q = &ret;
    head = &ret;
    while (p) {
        if (p->val == val) {
            q->next = p->next;
            free(p);
            p = q->next;
        }else {
            p = p->next;
            q = q->next;
        }
    }
    return head->next;
}
