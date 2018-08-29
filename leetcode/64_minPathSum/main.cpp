#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1
{
    int m;
    int n;
    vector< vector<int> > memo;
private:
    int findAnswer( vector<vector<int>>& grid, int x, int y )
    {
        if( x == m - 1 && y == n - 1 )
            return grid[x][y];
        if( memo[x][y] == -1 )
        {
            if (x == m - 1 && y < n - 1)
                memo[x][y] = grid[x][y] + findAnswer(grid, x, y + 1);
            else if (x < m - 1 && y == n - 1)
                memo[x][y] = grid[x][y] + findAnswer(grid, x + 1, y);
            else
            {
                int left = grid[x][y] + findAnswer(grid, x, y + 1);
                int right = grid[x][y] + findAnswer(grid, x + 1, y);
                memo[x][y] = min(left, right);
            }
        }
        return memo[x][y];
    }
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        m = grid.size();
        n = grid[0].size();
        memo = vector< vector<int> >( m, vector<int>( n, -1 ) );
        return findAnswer( grid, 0, 0 );
    }
};

class Solution2
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 初始化
        vector< vector<int> > memo( grid );
        // 第一行情况,只能从右侧来
        for( int i = 1; i < n; ++i )
            memo[0][i] = memo[0][i] + memo[0][i-1];
        // 第一列情况，只能从左侧来
        for( int j = 1; j < m; ++j )
            memo[j][0] = memo[j][0] + memo[j-1][0];

        for( int i = 1; i < m; ++i )
            for( int j = 1; j < n; ++j )
                memo[i][j] = min( memo[i][j-1], memo[i-1][j] ) + memo[i][j];

        return memo[m-1][n-1];
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}