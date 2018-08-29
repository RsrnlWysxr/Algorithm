#include <iostream>
#include <vector>
#include <string>

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
    vector<string> binaryTreePaths(TreeNode* root)
    {
         vector<string> res;
         if( !root )
             return res;
         if( !root->right && !root->left )
         {
             res.push_back( to_string( root->val ) );
             return res;
         }
         vector<string> leftS = binaryTreePaths( root->left );
         for( auto x : leftS )
             res.push_back( to_string( root-> val ) + "->" + x );
         vector<string> rightS = binaryTreePaths( root->right );
         for( auto x : rightS )
             res.push_back( to_string( root->val ) + "->" + x );
         return res;
    }
};




int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}