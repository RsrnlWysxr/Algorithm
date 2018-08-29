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
    bool hasPathSum(TreeNode* root, int sum)
    {
        if( !root )
            return false;
        if( !root->right && !root->left )
            return sum == root->val;
        if( hasPathSum( root->left, sum - root->val) )
            return true;
        if( hasPathSum( root->right, sum - root->val ) )
            return true;
        return false;
    }
};








int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}