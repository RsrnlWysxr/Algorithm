#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        vector< vector<int> > memo( nums.size(), vector<int>( S+1, 0 ) );
        memo[0][0] = 1;
        for( int i = 0; i < nums.size(); ++i )
            memo[i][0] = nums[i] == 0 ? 1 : 0;
        for( int j = 1; j <= S; j++ )
            for( int i = 0; i < nums.size(); i++ )
                memo[i][j] = memo[i-1][j-1] + memo[i+1][j-1];
        return memo[nums.size()-1][S];
    }
};





int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}