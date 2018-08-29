#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
private:
    vector<int> memo;
    int findAnswer( vector<int>& nums, int target )
    {
        if( target == 0 )
            return 1;
        if( memo[target] == -1 )
        {
            int res = 0;
            for( int i = 0; i < nums.size(); ++i )
                if( target >= nums[i] )
                    res += findAnswer( nums, target - nums[i] );
            memo[target] = res;
        }
        return memo[target];
    }
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        if( nums.empty() )
            return 0;
        memo = vector<int>( target+1, -1 );
        return findAnswer( nums, target );
    }
};

class Solution
{
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<int> memo( target+1, 0 );
        memo[0] = 1;
        for( int i = 1; i < target+1; ++i )
            for( int j = 0; j < nums.size(); ++j )
                if( i >= nums[j] )
                    memo[i] += memo[i-nums[j]];
        return memo[target];
    }
};



int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}