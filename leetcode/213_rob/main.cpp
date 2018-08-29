#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
private:
    // 考虑在[star...index]偷窃的最大值
    int findAnswer( vector<int>& nums, int index, int star, vector<int>& memo )
    {
        if( index < star )
            return 0;
        if( memo[index] == -1 )
        {
            int res = 0;
            for ( int i = index; i >= star; --i )
                res = max( res, nums[i] + findAnswer( nums, i - 2, star, memo ) );
            memo[index] = res;
        }
        return memo[index];
    }
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if( n == 0 )
            return 0;
        if( n == 1 )
            return nums[0];
        vector<int> memo1( nums.size(), -1 );
        vector<int> memo2( nums.size(), -1 );
        return max( findAnswer( nums, n-2, 0, memo1 ), findAnswer( nums, n-1, 1, memo2 ) );
    }
};
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if( n == 0 )
            return 0;
        if( n == 1 )
            return nums[0];
        vector<int> memo1( n, 0 );      // [0...n-2]
        vector<int> memo2( n, 0 );      // [1...n-1]
        memo1[0] = nums[0];
        memo2[1] = nums[1];
        for( int i = 1; i <= n - 2; ++i )
            memo1[i] = max( memo1[i-1], nums[i] + ( i-2 >= 0 ? memo1[i-2] : 0 ) );
        for( int i = 2; i <= n - 1; ++i )
            memo2[i] = max( memo2[i-1], nums[i] + memo2[i-2] );
        return max( memo1[n-2], memo2[n-1] );
    }
};




int main()
{
    vector<int> nums = { 2,7,9,3,1 };
    cout << Solution().rob( nums );
    return 0;
}