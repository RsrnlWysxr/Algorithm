#include <iostream>
#include <queue>

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
    bool isSymmetric(TreeNode* root)
    {
        if( !root )
            return true;
        queue<TreeNode*> q;
        queue<TreeNode*> p;
        q.push( root );
        p.push( root );
        while( !q.empty() && !p.empty() )
        {
            auto fq = q.front();
            q.pop();
            auto fp = p.front();
            p.pop();

            if( !fq && !fp )
                continue;
            if( !fq || !fp )
                return false;
            if( fp->val != fq->val )
                return false;
            q.push( fq->left );
            q.push( fq->right );

            p.push( fp->right );
            p.push( fp->left );
        }
        return q.empty() && p.empty();
    }
};


class Solution2
{
private:
    bool isSymmetric( TreeNode* node1, TreeNode* node2 )
    {
        if( !node1 && !node2 )
            return true;
        if( !node1 || !node2 )
            return false;
        if( node1->val != node2->val )
            return false;

        return isSymmetric( node1->left, node2->right )
            && isSymmetric( node1->right, node2->left );
    }
public:
    bool isSymmetric(TreeNode* root)
    {
        return isSymmetric( root, root );
    }
};






int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}