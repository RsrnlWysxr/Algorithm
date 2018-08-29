#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Solution1
{
public:
    // 最短路径问题
    // BFS
    int numSquares(int n)
    {
        if( n == 0 )
            return 0;

        queue< pair< int , int > > q;
        vector<bool> visited( n+1, false );

        q.push( make_pair( n, 0 ) );
        visited[n] = true;
        while( !q.empty() )
        {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            // 迭代邻边

            for( int i = 0; num - i * i >= 0; ++i )
            {
                int a = num - i * i;
                if( !visited[a] )
                    if( a == 0 )
                        return step + 1;
                    q.push( make_pair( a, step + 1 ) );
                    visited[a] = true;
            }
        }
    }
};

class Solution2
{
private:
    vector<int> memo;
    int findAnswer( int n )
    {

        if( n == 0 )
            return 0;
        if( memo[n] == -1 )
        {
            int res = INT_MAX;
            for (int i = 1; n - i * i >= 0; ++i)
                res = min(findAnswer(n - i * i) + 1, res);
            memo[n] = res;
        }
        return memo[n];
    }
public:
    int numSquares(int n)
    {
        memo = vector<int>( n + 1, -1 );
        return findAnswer( n );
    }
};

class Solution3
{
public:
    int numSquares(int n)
    {
        vector<int> memo( n + 1, INT_MAX );
        memo[0] = 0;
        for( int i = 1; i <= n; ++i )
            for( int j = 1; i - j * j >= 0; ++j )
                memo[i] = min( memo[i], memo[i-j*j] + 1 );
        return memo[n];
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}