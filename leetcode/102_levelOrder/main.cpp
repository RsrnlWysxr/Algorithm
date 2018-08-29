#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if( !root )
            return res;
        queue< pair< TreeNode*, int > > q;
        q.push( make_pair( root, 0 ) );
        while( !q.empty() )
        {
            auto top = q.front();
            q.pop();
            if( top.second == res.size() )
                res.push_back( vector<int>() );
            res[top.second].push_back( top.first->val );
            if( top.first->left )
                q.push( make_pair( top.first->left, top.second + 1 ) );
            if( top.first->right )
                q.push( make_pair( top.first->right, top.second + 1) );
        }
        return res;
    }
};






int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}