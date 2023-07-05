TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	/* mujhe ek doubt hai, maan lo ki mai reference ke help se value ko extract kr leta hu, toh kya yeh possible nhi hai ki ek tree mei waise same value aur kisi k naa ho? agar hogi toh answer hi galat aayega? 
    
    !TODO: ispe sochna pdega bhai!!!!! */

    if(root == nullptr or root == p or root == q)
    {
        return root;
    }
    TreeNode<int>* left = LCAinaBST(root->left, p, q);
    TreeNode<int>* right = LCAinaBST(root->right, p, q);

    if(left == nullptr) return right;
    if(right == nullptr) return left;

    return root;
}