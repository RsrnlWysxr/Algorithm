#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();        // 行
        int n = obstacleGrid[0].size();     // 列
        vector< vector<int> > memo( m, vector<int>( n, 0 ) );
        // 初始化终点
        if( obstacleGrid[m-1][n-1] == 0 )
            memo[m-1][n-1] = 1;
        // 初始化最后一行（终点朝左走）
        for( int i = n - 2; i >= 0; --i )
            if( obstacleGrid[m-1][i] == 1 )
                memo[m-1][i] = 0;
            else
                memo[m-1][i] = memo[m-1][i+1];
        // 初始化最后一列
        for( int j = m - 2; j >= 0; --j )
            if( obstacleGrid[j][n-1] == 1 )
                memo[j][n-1] = 0;
            else
                memo[j][n-1] = memo[j+1][n-1];
        // 动态规划
        for( int i = m - 2; i >= 0; --i )
            for( int j = n - 2; j >= 0; --j )
                if( obstacleGrid[i][j] == 1 )
                    memo[i][j] = 0;
                else
                    memo[i][j] = memo[i+1][j] + memo[i][j+1];

        return memo[0][0];
    }
};


int main()
{
    vector<vector<int>> vec = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{0,0},{0,1},{0,0},{0,0},{1,0},{0,0},{0,0},{0,1},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,1},{0,0},{0,0},{0,0},{0,0},{1,0},{0,0},{0,0},{0,0},{0,0}};
    Solution().uniquePathsWithObstacles(vec);
    return 0;
}