/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int getHeight(TreeNode<int> *root, int &diameter)
{
    if(root == nullptr) return 0;
    int lh = getHeight(root->left, diameter), rh =  getHeight(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	int diameter = 0;
    getHeight(root, diameter);
    return diameter;
}
