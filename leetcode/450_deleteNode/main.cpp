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
private:
    int findmin( TreeNode* node )
    {
        while( node->left )
        {
            node = node->left;
        }
        return node->val;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if( !root )
            return root;
        if( key > root->val )
            root->right =  deleteNode( root->right, key );
        if( key < root->val )
            root->left = deleteNode( root->left, key );
        if( key == root->val )
        {
            if( !root->left )
            {
                auto ret = root->right;
                delete root;
                return ret;
            }
            if( !root->right )
            {
                auto ret = root->left;
                delete root;
                return ret;
            }
            auto replace = new TreeNode( findmin( root->right ) );
            replace->left = root->left;
            replace->right = deleteNode( root->right, replace->val );
            delete root;
            return replace;
        }
        return root;
    }
};






int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}