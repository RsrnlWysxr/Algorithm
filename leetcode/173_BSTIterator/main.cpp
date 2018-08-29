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

class BSTIterator
{
private:
    vector<int> data;
    int index;

    void inOrder( TreeNode* node )
    {
        if( node )
        {
            inOrder( node->left );
            data.push_back( node->val );
            inOrder( node->right );
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        data.clear();
        inOrder( root );
        index = 0;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return index < data.size();
    }

    /** @return the next smallest number */
    int next()
    {
        return data[index++];
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}