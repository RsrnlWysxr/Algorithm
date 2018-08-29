#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
private:
    // 考虑在[0...index]范围抢劫的最大收益
    vector<int> memo;
    // 考虑在[0...index]范围内抢劫
    int findAnswer( vector<int>& nums, int index )
    {
        if( index < 0 )
            return 0;
        if( memo[index] == -1 )
        {
            int res = 0;
            for (int i = index; i >= 0; --i)
            {
                res = max(res, nums[i] + findAnswer(nums, i - 2));
            }
            memo[index] = res;
        }
        return memo[index];
    }
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        memo = vector<int>( n, -1 );
        return findAnswer( nums, nums.size() - 1 );
    }
};

class Solution2
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if( n == 0 )
            return 0;

        vector<int> memo( n, 0 );   // 考虑在[0...index]范围抢劫的最大收益
        memo[0] = nums[0];
        for( int i = 1; i < n; ++i )
            for( int j = i; j >= 0 ; --j )
                memo[i] = max( memo[i], nums[j] + ( j - 2 >= 0 ? memo[j - 2] : 0 ) );

        return memo[n-1];
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

        vector<int> memo( n, 0 );   // 考虑在[0...index]范围抢劫的最大收益
        memo[0] = nums[0];
        for( int i = 1; i < n; ++i )
            memo[i] = max( memo[i-1] , nums[i] + ( i - 2 >= 0 ? memo[i-2] : 0 ) );

        return memo[n-1];
    }
};






int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}