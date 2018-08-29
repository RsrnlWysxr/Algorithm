#include <iostream>
#include <vector>

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
    int sumOfLeftLeaves(TreeNode* root)
    {
        int res = 0;
        if( !root )
            return 0;
        if( root->left && !root->left->left && !root->left->right )
            res += root->left->val;
        res += sumOfLeftLeaves( root->left );
        res += sumOfLeftLeaves( root->right );
        return res;
    }
};






int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}