#include <iostream>
#include <climits>

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
private:
    int getHeight( TreeNode* node )
    {
        if( !node )
            return 0;
        return max( getHeight( node->left ), getHeight( node->right ) ) + 1;
    }
public:
    bool isBalanced(TreeNode* root)
    {
        if( !root )
            return true;

        int ret = INT_MAX;
        if( isBalanced( root->right ) && isBalanced( root->left ) )
            ret = abs( getHeight( root->right) - getHeight( root->left) );
        return ret <= 1;
    }
};




int main()
{
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    cout << Solution().isBalanced( root );
    return 0;
}