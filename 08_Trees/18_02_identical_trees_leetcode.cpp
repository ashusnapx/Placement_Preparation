/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool isSameTree(TreeNode *r1, TreeNode *r2)
        {
            if (r1 == nullptr and r2 == nullptr) return true;
            if (r1 == nullptr or r2 == nullptr) return false;
            bool leftIdentical = isSameTree(r1->left, r2->left);
            bool rightIdentical = isSameTree(r1->right, r2->right);
            return (r1->val == r2->val) and leftIdentical and rightIdentical;
        }
};