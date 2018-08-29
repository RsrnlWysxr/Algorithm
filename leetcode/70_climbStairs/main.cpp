#include <iostream>
#include <vector>

using namespace std;

// 记忆化搜索

class Solution1
{
private:
    vector<int> memo;
    int findAnswer( int n  )
    {
        if( n == 1 )
            return 1;
        if( n == 2 )
            return 2;
        if( memo[n] == -1 )
            memo[n] = findAnswer( n - 1 ) + findAnswer( n - 2 );
        return memo[n];
    }
public:
    int climbStairs(int n)
    {
        memo = vector<int>( n + 1, -1 );
        return findAnswer( n );
    }
};

// 动态规划
class Solution2
{
public:
    int climbStairs(int n)
    {
        vector<int> memo( n + 1, -1 );
        memo[1] = 1;
        memo[2] = 2;
        for( int i = 2; i <= n ; ++i )
            memo[n] = memo[n-1] + memo[n-2];
        return memo[n];
    }
};





int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}