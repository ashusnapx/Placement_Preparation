#include <bits/stdc++.h> 
/*
Following is the structure of Tree Node

class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/
void helper(TreeNode* root, vector<int> &result)
{
    if(root == nullptr) return;
    helper(root->left, result);
    helper(root->right, result);
    result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root)
{
    // Write your code here
    vector<int> result;	
    helper(root, result);
    return result;
}
