#include <iostream>
#include <vector>
#include <sstream>
using namespace std;




struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1
{
private:
    vector<string>sumString( TreeNode* node )
    {
        vector<string> res;
        if( !node )
            return res;
        if( !node->right && !node->left )
            res.push_back( to_string( node->val ) );
        vector<string> leftS = sumString( node->left );
        for( auto x : leftS )
            res.push_back( to_string( node->val ) + x );
        vector<string> rightS = sumString( node->right );
        for( auto y : rightS )
            res.push_back( to_string( node->val ) + y );
        return res;
    }

public:
    int sumNumbers(TreeNode* root)
    {
        if( !root )
            return 0;
        vector<string> sres = sumString( root );
        vector<int> nums;
        for( auto x : sres )
        {
            int num = stoi( x );
            nums.push_back( num );
        }
        int ret = 0;
        for( auto y : nums )
            ret += y;
        return ret;
    }
};

class Solution2
{
private:
    int sumNumbers( TreeNode* node, int sum )
    {
        if( !node )
            return sum;
        sum = sum * 10 + node->val;
        if( !node->left && !node->right ) return sum;
        return sumNumbers( node->left, sum ) + sumNumbers( node->right, sum );
    }
public:
    int sumNumbers(TreeNode* root)
    {
        return sumNumbers( root ,0 );
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}