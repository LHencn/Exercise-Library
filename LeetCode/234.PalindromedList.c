/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *fast = head, *slow = head, *temp;
    while (fast) {//快慢指针找到链表中点
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
    }
    if (slow) {//将链表中点next指针指向空
        fast = slow->next;
        slow->next = NULL;
    }
    while (fast) {//反转链表
        temp = fast->next;
        fast->next = slow;
        slow = fast;
        fast = temp;
    }
    fast = head;
    while (fast && slow) {//左右遍历
        if (fast->val != slow->val)
            return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}
bool isPalindrome(struct ListNode* head) {
    struct ListNode *fast = head, *slow = head, *temp = NULL;
    while (fast) {//快慢指针找到链表中点
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
    }
    while (slow) {
        fast = slow->next;
        slow->next = temp;
        temp = slow;
        slow = fast;
    }
    fast = head;
    slow = temp;
    while (fast && slow) {
        if (fast->val != slow->val)
            return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}
