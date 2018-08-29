#include <iostream>



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
    int findpath( TreeNode* node, int sum )
    {
        if( !node )
            return 0;
        int ret = 0;
        if( node->val == sum )
            ret += 1;
        ret += findpath( node->left, sum - node->val );
        ret += findpath( node->right, sum - node->val );

        return ret;
    }
public:
    int pathSum(TreeNode* root, int sum)
    {
        if( !root )
            return 0;
        int res = findpath( root, sum );        // 包含当前节点
        res += pathSum( root->left, sum );      // 不包含当前节点
        res += pathSum( root->right, sum );

        return res;
    }
};






int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}