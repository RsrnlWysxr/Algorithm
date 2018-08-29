#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        if( !root )
            return res;
        queue< pair< TreeNode*, int > > q;
        vector<vector<int>> tmp;
        q.push( make_pair( root, 0 ) );
        while( !q.empty() )
        {
            auto node = q.front().first;
            auto level = q.front().second;
            q.pop();
            if( tmp.size() == level )
                tmp.push_back( vector<int>() );
            tmp[level].push_back( node->val );
            if( node->left )
                q.push( make_pair( node->left, level + 1 ) );
            if( node->right )
                q.push( make_pair( node->right, level + 1) );
        }
        for( int i = 0; i < tmp.size(); ++i )
        {
            res.push_back( *( tmp[i].end() - 1 ) );
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}