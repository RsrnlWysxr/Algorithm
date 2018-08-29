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
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> res;
        if( !root )
            return res;
        if( !root->left && !root->right && root->val == sum )
            res.push_back( vector<int>{ root->val } );
        vector<vector<int>> leftR = pathSum( root->left, sum - root->val );
        if( !leftR.empty() )
        {
            for( auto x : leftR )
            {
                vector<int> push = { root->val };
                for( auto y: x )
                {
                    push.push_back( y );
                }
                res.push_back( push );
            }
        }
        vector<vector<int>> rightR = pathSum( root->right, sum - root->val );
        if( !rightR.empty() )
        {
            for( auto x : rightR )
            {
                vector<int> push = { root->val };
                for( auto y: x )
                {
                    push.push_back( y );
                }
                res.push_back( push );
            }
        }
        return res;

    }
};





int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}