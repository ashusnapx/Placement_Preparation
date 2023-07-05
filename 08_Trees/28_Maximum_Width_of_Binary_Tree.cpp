#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    if(root == nullptr) return 0;

    if(root -> left == nullptr and root -> right == nullptr) return 1;

    int ans = 0;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while(!q.empty())
    {
        int size = q.size();
        int minIndex = q.front.second;
        int first, last;
        for(int i = 0; i < size; i++)
        {
            int currentIndex = q.front.second - minIndex;
            TreeNode<int> *node = q.front().first;
            q.pop();

            if(i == 0) first = currentIndex;
            if(i == size - 1) last = currentIndex;

            if(node -> left) q.push({node -> left, currentIndex * 2 + 1});
            if(node -> right) q.push({node -> right, currentIndex * 2 + 2});
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
}

/* 
Imp: so a binary tree can always've atmax 2 nodes, which number of nodes can be 0, 1 or 2. so let suppose a node has index 'i', 
if 0 based indexing,
then node at just left will've index '2 x i + 1' and right one will've '2 x i + 2'
if 1 based indexing,
then node at just left will've index '2 x i' and right one will've '2 x i + 1'

but we cannot use them like this, coz they'll cause overflow and which is not good.
*/


/* vvviiipppp
since we applied a trick to tackle the integer overflow here,yes we did,but through this method we just ensure that the index we push everytime just comes under INT_MAX,and index difference is always under singed 32 bit ,i.e at max below 2^32 as stated in question itself. At everytime we are pushing (2*index+1) or (2*index+2),so its not exactly twice,its getting more than that ,thats why we need to typecast with long long.Hope its clear now.
*/