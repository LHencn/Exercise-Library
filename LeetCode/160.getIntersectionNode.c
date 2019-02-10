/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//两遍循环,时间复杂度为O(n^2)
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    while (p) {
        q = headB;
        while (q) {
            if (q == p)
                return q;
            q = q->next;
        }
        p = p->next;
    }
    return NULL;
}

//定义两个指针分别进行链表遍历，若到链表尾部则转到另一个链表开头继续遍历，直至两指针相等或都等于NULL，此时即为结果
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    struct ListNode *pA = headA, *pB = headB;
    while(pA != pB) {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
    }
    return pA;
}
