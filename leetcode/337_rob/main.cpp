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
private:
    int findAnswer( TreeNode* node, bool include )
    {
        if( !node )
            return 0;

        int res = 0;

        res = findAnswer( node->left, true ) + findAnswer( node->right, true );
        if( include )
            res = max( node->val + findAnswer( node->left, false ) + findAnswer( node->right, false ), res );

        return res;
    }
public:
    int rob(TreeNode* root)
    {
        return findAnswer( root, true );
    }
};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}