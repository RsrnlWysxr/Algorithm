#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        if( n == 0 )
            return 0;
        vector<int> memo( n, 1 );
        for( int i = 1; i < n; ++i )
            for( int j = 0; j < i; ++j )
                if( nums[j] < nums[i] )
                    memo[i] = max( memo[i], memo[j] + 1 );
        int res = 1;
        for( auto x : memo )
            res = max( x, res );
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}