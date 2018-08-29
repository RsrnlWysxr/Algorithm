#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
    int m;
    int n;
    vector< vector<int> > memo;
private:
    int findAnswer( int x, int y )
    {
        if( x == m - 1 && y == n - 1 )
            return 1;
        if( memo[x][y] == -1 )
        {
            if (x == m - 1 && y < n - 1)
                memo[x][y] = findAnswer(m - 1, y + 1);
            else if (x < m - 1 && y == n - 1)
                memo[x][y] = findAnswer(x + 1, n - 1);
            else
                memo[x][y] = findAnswer(x + 1, y) + findAnswer(x, y + 1);
        }
        return memo[x][y];
    }
public:
    int uniquePaths(int m, int n)
    {
        this->m = m;
        this->n = n;
        memo = vector< vector<int> >( m+1 , vector<int>( n+1, -1 ) );
        return findAnswer( 0, 0 );
    }
};

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector< vector<int> > memo( m , vector<int>( n, 1 ) );
        for( int i = 1; i < m; ++i  )
            for( int j = 1; j < n; ++j )
                memo[i][j] = memo[i-1][j] + memo[i][j-1];
        return memo[m-1][n-1];
    }
};




int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}