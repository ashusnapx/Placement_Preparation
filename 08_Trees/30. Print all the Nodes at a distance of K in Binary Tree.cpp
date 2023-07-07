/*************************************************************

    Following is the Binary Tree node structure for reference:

    class BinaryTreeNode{
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
void visitedParents()
{

}
vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    unordered_map

}

/* 
1. mujhe bfs traversal krna hai, iss liye main sabse pehle queue bnaunga aur phir usmein mai root ko insert kr dunga
2. start iterating in queue
3. now put left and right nodes (if available) inside queue aka level order
4. carry a visited hash (yeh bhai graph k concept bhi ghusa diye)
*/

/* 
imp. points about binary tree:
1. 2 node ki values same bhi ho skti hn, don't get confused by BST.
*/