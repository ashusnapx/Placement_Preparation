void preorderHelper(TreeNode* node, vector<int>& result)
{
    if (node == nullptr)
    {
        return;
    }
    
    result.push_back(node->val);  // Add the current node's value to the result vector
    
    preorderHelper(node->left, result);   // Recursively traverse the left subtree
    
    preorderHelper(node->right, result);  // Recursively traverse the right subtree
}

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> result;
    preorderHelper(root, result);
    return result;
}