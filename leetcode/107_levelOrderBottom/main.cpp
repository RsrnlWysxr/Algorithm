#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> res;
        if( !root )
            return res;

        stack<vector<int>> s;
        queue< pair< TreeNode*, int> > q;

        q.push( make_pair( root, 0 ) );
        while( !q.empty() )
        {
            auto node = q.front().first;
            auto level = q.front().second;
            q.pop();
            if( level == res.size() )
                res.push_back( vector<int>() );
            res[level].push_back( node->val );
            if( node->left )
                q.push( make_pair( node->left, level + 1 ) );
            if( node->right )
                q.push( make_pair( node->right, level + 1 ) );
        }
        reverse( res.begin(), res.end() );
        return res;
    }
};











int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}