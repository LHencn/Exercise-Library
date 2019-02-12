/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q|| q == NULL && p)
        return false;
    if (p == NULL && q == NULL) 
        return true;
    if (p->val != q->val)
        return false;
    if (isSameTree(p->left, q->left) == 0)
        return false;
    if (isSameTree(p->right, q->right) == 0)
        return false;
    return true;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if (p && q && p->val == q->val)
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    return false;
}
