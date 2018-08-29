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
public:
    // 在root中寻找p和q
    // 如果p和q都在root所在的二叉树中, 则返回LCA
    // 如果p和q只有一个在root所在的二叉树中, 则返回p或者q
    // 如果p和q均不在root所在的二叉树中, 则返回NULL
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if( !root )
            return NULL;
        // 找到就返回
        if( root == q || root == p )
            return root;
        // 去左边找
        auto left = lowestCommonAncestor( root->left, p, q );
        // 去右边找
        auto right = lowestCommonAncestor( root->right, p, q );
        // 左右都找到，证明在两侧，该节点就是LCA
        if( left && right )
            return root;
        // 只在左边有，证明在左边下层已经找到了，直接返回即可
        if( left )
            return left;
        // 只在右边有，证明在右边的下层已经找到了，直接返回即可
        if( right )
            return right;
        // 左右都没找到
        return NULL;
    }
};






int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}