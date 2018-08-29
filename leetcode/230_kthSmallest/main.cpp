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
    TreeNode* kthSmallestNode( TreeNode* node, int k, int& index )
    {
        if( !node )
            return NULL;
        // 去左孩子找
        auto resl = kthSmallestNode( node->left, k, index );
        // 找到了就返回
        if( resl )
            return resl;
        // 没找到，考察当前节点，是的话就返回
        index++;
        if( k == index )
            return node;
        // 当前节点也没找到，去右孩子
        auto resr = kthSmallestNode( node->right, k, index );
        // 找到了就返回
        if( resr )
            return resr;
        // 左中右都找了，没有，返回NULL
        return NULL;
    }
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int index = 0;
        return kthSmallestNode( root, k, index )->val;
    }
};








int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}