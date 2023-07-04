#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool helper(TreeNode<int>* root, vector<int>& ans, int nodeValue)
{
    if( root == nullptr ) return false;

    ans.push_back(root -> data);

    if(root -> data == nodeValue) return true;

    if(helper(root->left, ans, nodeValue) or helper(root->right, ans, nodeValue))
    {
        return true;
    }

    ans.pop_back();
    return false;
}

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	/* mujhe ek doubt hai, maan lo ki mai reference ke help se value ko extract kr leta hu, toh kya yeh possible nhi hai ki ek tree mei waise same value aur kisi k naa ho? agar hogi toh answer hi galat aayega? 
    
    !TODO: ispe sochna pdega bhai!!!!! */

    TreeNode<int>* ans = nullptr;
    vector<int> ans1, ans2;
    if(root == nullptr) return ans;

    helper(root, ans1, P->data);
    helper(root, ans2, Q->data);

    int n = ans1.size(), m = ans2.size();
    vector<int> ok;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(ans1[i] == ans2[j])
            {
                ok.push_back(ans1[i]);
            }
        }
    }

    if(ok.empty())
        return ans;

    ans = new TreeNode<int>(ok[ok.size()-1]);  // Allocate memory for the result
    return ans;
}

/* lowest common ancestor means the node that exists at the deepest level and you can connect it with both nodes */