#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int getHeight(BinaryTreeNode<int>* root)
{
    if(root == nullptr) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBalancedBT(BinaryTreeNode<int>* root) 
{
    if(root == nullptr) return true;

    int left_height = getHeight(root -> left);
    int right_height = getHeight(root -> right);

    if(abs(left_height - right_height) < 1) return true;
    return false;
} 