#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// Time Compexity： O(n)
/// Space Compexity: O(1)

class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int l = 0, r = -1 ; // 在[l...r]的窗口内求值
        int res = nums.size() + 1;  // 初始化返回值
        int sum = 0;      // 初始化和
        while( l < nums.size() )
        {
            if( sum < s && r + 1 < nums.size() )
                sum += nums[++r];
            else
                sum -= nums[l++];
            if( sum >= s )
                res = min( res, r - l + 1 );
        }
        if( res == nums.size() + 1 )
            return 0;
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}