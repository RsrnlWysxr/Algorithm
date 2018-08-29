#include <iostream>

using namespace std;

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if( !root )
            return NULL;
        if( p->val > root->val && q->val > root->val )
            return lowestCommonAncestor( root->right, p, q );
        if( p->val < root->val && q->val < root->val )
            return lowestCommonAncestor( root->left, p, q );
        else
            return root;
    }
};


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}