vector<int> preorder_traversal(TreeNode* root)
{
    vector<int> result;

    if(root == nullptr) return result;

    stack<TreeNode*> st;

    st.push(root);

    while(!st.empty())
    {
        root = st.top();
        st.pop();

        result.push_back()
    }
}