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
    TreeNode* invertTree(TreeNode* root)
    {
        if( !root )
            return NULL;

        root->left = invertTree( root->left );
        root->right = invertTree( root->right );
        swap( root->right, root->left );

        return root;
    }
};








int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}