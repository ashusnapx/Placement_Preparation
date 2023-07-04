#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
bool helper(TreeNode<int> *root, vector<int> &ans, int nodeValue)
{
    if(root == nullptr) return false;

    ans.push_back(root -> data);

    if(root -> data == nodeValue) return true;

    /* recursion call to nodes present in left and right of root */
    if(helper(root->left, ans, nodeValue) or helper(root->right, ans, nodeValue))
    {
        return true;
    }

    /* control will come here only when it doesn't finds the designated target or node, and in that case i'll remove the node value inserted in array for checking */
    ans.pop_back();

    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int nodeValue)
{
    vector<int> ans;

    if(root == nullptr) return ans;

    // if(root -> data == nodeValue) ans.push_back(root -> data);

    helper(root, ans, nodeValue);

    return ans;
}
