#include <iostream>
#include <vector>
#include <stack>

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

public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        if( !root )
            return res;
        stack<TreeNode*> s;
        auto cur = root;
        while( cur || !s.empty() )
        {
            while( cur )
            {
                s.push( cur );
                cur = cur->left;
            }
            // 循环结束，左节点已经全部入栈
            auto top = s.top();
            s.pop();
            res.push_back( top->val );
            cur = top->right;
        }
        return res;
    }
};
class Solution2
{
private:
    struct Command
    {
        string s;   // "go" "visit"
        TreeNode* node;
        Command( string s,TreeNode* node ):s(s),node(node){}
    };

public:
    vector<int> inorderTraversal(TreeNode* root)
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
                if( command.node->right )
                    s.push( Command( "go", command.node->right ) );
                s.push( Command( "visit", command.node ) );
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