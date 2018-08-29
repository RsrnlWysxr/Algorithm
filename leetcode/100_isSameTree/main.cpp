#include <iostream>



struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if( (!q && p ) || ( q && !p ) )
            return false;

        if( !p && !q )
            return true;

        if( p->val != q->val )
            return false;

        if( isSameTree( p->left, q->left ) && isSameTree( p->right, q->right ) )
            return true;
        return false;
    }
};








int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}