/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {//node->next节点给node节点赋值,然后删除node->next节点
    node->val = node->next->val;
    struct ListNode *p = node->next;
    node->next = p->next;
    free(p);
}

void deleteNode(struct ListNode* node) {
    struct ListNode *p;
    while (node->next) {
        node->val = node->next->val;
        p = node;
        node = node->next;
    }
    p->next = NULL;
    free(node);
}
