#include <iostream>
#include <vector>

using namespace std;



class Solution1
{
private:
    vector< vector<int> > memo;
    bool findAnswser( vector<int>& nums, int index, int target )
    {
        if( index < 0 || target < 0 )
            return false;
        if( target == 0 )
            return true;
        if( memo[index][target] == -1 )
            memo[index][target] = findAnswser( nums, index - 1, target ) || findAnswser( nums, index - 1, target - nums[index] );
        return memo[index][target];
    }
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for( int i = 0; i < nums.size(); ++i )
            sum += nums[i];

        if( sum % 2 )
            return false;

        memo = vector< vector<int> >( nums.size(), vector<int>( sum/2 + 1, -1 ) );

        return findAnswser( nums, nums.size()-1, sum/2 );
    }
};

class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for( auto x: nums )
            sum += x;
        if( sum%2 )
            return false;
        vector<bool> memo( sum/2+1, false );
        // 初始化第一行
        for( int i = 0; i <= sum/2; ++i )
            memo[i] = ( nums[0] == i );
        for( int i = 1; i < nums.size(); ++i )
            for( int j = sum/2; j >= nums[i]; --j )
                memo[j] = memo[j] || memo[j-nums[i]];
        return memo[sum/2];
    }
};



int main()
{
    vector<int> nums = {1,5,11,5};
    cout << Solution().canPartition( nums );
    return 0;
}