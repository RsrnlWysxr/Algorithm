#include <iostream>
#include <stack>
#include <vector>

using namespace std;



struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution1
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if( !root )
            return res;

        stack<TreeNode*> s;
        stack<TreeNode*> r;
        s.push( root );
        while( !s.empty() )
        {
            auto top = s.top();
            r.push( top );
            s.pop();
            if( top->left )
                s.push( top->left );
            if( top->right )
                s.push( top->right );
        }
        while( !r.empty() )
        {
            auto top = r.top();
            r.pop();
            res.push_back( top->val );
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if( !root )
            return res;
        auto cur = root;
        TreeNode* tmp = NULL;
        stack<TreeNode*> s;
        while( cur || !s.empty() )
        {
            while( cur )
            {
                s.push( cur );
                cur = cur->left;
            }
            auto top = s.top();
            if( top->right == NULL || top->right == tmp )
            {
                res.push_back( top->val );
                s.pop();
                tmp = top;
            }
            else
                cur = top->right;
        }
        return res;
    }
};

class Solution3
{
private:
    struct Command
    {
        string s;   // "go" "visit"
        TreeNode* node;
        Command( string s,TreeNode* node ):s(s),node(node){}
    };

public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if ( !root )
            return res;
        stack<Command> s;
        s.push( Command( "go", root ) );
        while( !s.empty() )
        {
            Command command = s.top();
            s.pop();
            if( command.s == "visit" )
                res.push_back( command.node->val );
            else    // go
            {
                s.push( Command( "visit", command.node ) );
                if( command.node->right )
                    s.push( Command( "go", command.node->right ) );
                if( command.node->left )
                    s.push( Command( "go", command.node->left ) );
            }
        }
        return res;
    }
};







int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}