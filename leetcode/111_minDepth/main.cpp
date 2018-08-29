#include <iostream>
#include <w32api/ntdef.h>
#include <climits>


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
    int minDepth(TreeNode* root)
    {
        if( !root )
            return 0;
        if( !root->right && !root->left )
            return 1;
        int ret = INT_MAX;
        if( root->left )
            ret = min( ret, 1 + minDepth( root->left) );
        if( root->right )
            ret = min( ret, 1+ minDepth( root->right ) );
        return ret;
    }
};





int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}