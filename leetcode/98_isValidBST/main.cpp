#include <iostream>
#include <vector>
#include <climits>


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
    void inOrder(TreeNode* node,std::vector<int>& arr)
    {
        if(node == nullptr)
            return;
        inOrder(node->left,arr);
        arr.push_back(node->val);
        inOrder(node->right,arr);
    }
public:
    bool isValidBST(TreeNode* root)
    {
        std::vector<int> arr;
        inOrder(root,arr);
        for(int i = 1 ; i < arr.size() ; i ++)
        {
            if( arr[i - 1] >= arr[i])
                return false;
        }
        return true;
    }
};

class Solution
{
    bool isValidBST( TreeNode* node, long min, long max )
    {
        if( !node )
            return true;
        if( node->val <= min || node->val >= max )
            return false;
        return isValidBST( node->left, min, node->val ) && isValidBST( node->right, node->val, max );
    }
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};











int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}