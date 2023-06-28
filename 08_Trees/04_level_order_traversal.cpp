vector<vector<int>> levelOrder(TreeNode* root)
{
    /* creating a 2d array so that i can return result */
    vector<vector<int>> result;

    /* base case */
    if(root == nullptr)
    {
        return result;
    }

    /* create a queue to maintan level */
    queue<TreeNode<int> *> q;

    /* i'll push the root first */
    q.push(root);

    /* traverse until the queue gets emptied */
    while(!q.empty())
    {
        /* store the size of queue */
        int size = q.size();

        vector<int> level; // idk why i'm creating this?

        for(int i = 0; i < size; i++)
        {
            /* access the front element of queue, which is FIFO, first in first out */
            TreeNode* node = q.front();

            /* after storing it in TreeNode<int> * variable, take it out from queue */
            q.pop();

            /* if extracted front node ie. node has nodes in left, then-> */
            if(node -> left != nullptr) q.push(node -> left);

             /* if extracted front node ie. node has nodes in right, then-> */
            if(node -> right != nullptr) q.push(node -> right);

            level.push_back(node -> val);
        }
        
        result.push_back(level);
    }

    return result;
}