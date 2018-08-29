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
private:
    int count;

    void ccount( TreeNode* node )
    {
        if( !node )
            return;

        ccount( node->left );
        ccount( node->right );

        count++;
    }

public:
    int countNodes(TreeNode* root)
    {
        ccount( root );
        return count;
    }
};









int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}