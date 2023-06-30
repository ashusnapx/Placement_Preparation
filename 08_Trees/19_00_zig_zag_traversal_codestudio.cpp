vector<int> zigzagTreeTraversal(TreeNode<int>* root) {
    vector<int> result; // To store the traversal result
    
    if (root == nullptr)
        return result; // Return an empty vector if the tree is empty
    
    queue<TreeNode<int>*> q;
    q.push(root);
    
    bool leftToRight = true; // Flag to indicate the current direction of traversal
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size); // To store the elements of the current level
        
        for (int i = 0; i < size; i++) {
            TreeNode<int>* node = q.front();
            q.pop();
            
            int index = (leftToRight) ? i : (size - 1 - i); // Determine the index based on the traversal direction
            
            level[index] = node->data; // Store the node's data in the level vector
            
            // Add the left and right children of the current node to the queue
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        
        leftToRight = !leftToRight; // Flip the traversal direction for the next level
        
        // Append the current level's elements to the result vector
        result.insert(result.end(), level.begin(), level.end());
    }
    
    return result; // Return the final traversal result
}
