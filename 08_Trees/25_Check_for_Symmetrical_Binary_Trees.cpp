/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool helper(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right)
{
    if(left == NULL or right == NULL) return left == right;

    // check root's value
    if(left->data != right->data) return false;

    return helper(left->left, right->right) and helper(left->right, right->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL) return true;
    return helper(root -> left, root -> right);    
}