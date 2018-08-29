#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
private:
    vector<int> memo;
    int findAnswer( int n )
    {
        if( n == 1 )
            return 1;
        if( memo[n] == -1 )
        {
            int res = -1;
            for (int i = 1; i <= n - 1; ++i)
                res = max3(res, i * (n - i), i * findAnswer(n - i));
            memo[n] = res;
        }
        return memo[n];
    }
    int max3( int i ,int j , int k )
    {
        return max( i , max( j, k ) );
    }

public:
    int integerBreak(int n)
    {
        memo = vector<int>( n+1, -1 );
        return findAnswer( n );
    }
};

class Solution2
{
private:
    int max3( int i ,int j , int k )
    {
        return max( i , max( j, k ) );
    }
public:
    int integerBreak(int n)
    {
        vector<int> memo( n+1, -1 );
        memo[1] = 1;
        for( int i = 2; i <= n ; ++i )
            for( int j = 1; j < i; ++j )
                memo[i] = max3( memo[i], j * ( i - j ), j * memo[i-j] );
        return memo[n];
    }
};


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}