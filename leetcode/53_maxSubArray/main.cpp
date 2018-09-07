#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        if( nums.empty() )
            return 0;
        int sum = 0;
        int maxSum = nums[0];
        for( int i = 0; i < nums.size(); ++i )
        {
            sum = max( sum + nums[i], nums[i] );
            maxSum = max( maxSum, sum );
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray( nums );
    return 0;
}