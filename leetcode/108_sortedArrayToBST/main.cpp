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

class Solution
{
private:
    TreeNode* sortedArrayToBST( vector<int>& nums, int l, int r )
    {
        if( l > r )
            return NULL;
        int mid = l + ( r - l ) / 2;
        auto node = new TreeNode( nums[mid] );
        node->left = sortedArrayToBST( nums, l, mid - 1 );
        node->right = sortedArrayToBST( nums, mid + 1, r );
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBST( nums, 0, nums.size() - 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}