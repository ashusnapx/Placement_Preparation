/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == nullptr and r2 == nullptr) return true;
        if(r1 == nullptr or r2 == nullptr) return false;
        bool leftIdentical = isIdentical(r1 -> left, r2 -> left);
        bool rightIdentical = isIdentical(r1 -> right, r2 -> right);
        return (r1 -> data == r2 -> data) and leftIdentical and rightIdentical;
    }
};