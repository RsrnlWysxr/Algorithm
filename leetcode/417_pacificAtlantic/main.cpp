#include <iostream>
#include <vector>

using namespace std;
// 从海洋的角度出发
// 能流向自己的就标记为true;
class Solution
{
private:
    int n, m;
    int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    bool inArea( int x , int y )
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs( vector<vector<int>>& matrix, int x , int y , vector< vector<bool> >& visited )
    {
        visited[x][y] = true;
        for( int i = 0; i < 4; ++i )
        {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            if( inArea( newx, newy ) && !visited[newx][newy] && matrix[x][y] <= matrix[newx][newy] )
                dfs( matrix, newx, newy, visited );
        }
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
        vector<pair<int, int>> res;
        n = matrix.size();
        if( n == 0 )
            return res;
        m = matrix[0].size();
        if( m == 0 )
            return res;
        vector< vector<bool> > topac( n, vector<bool>( m, false ) );
        vector< vector<bool> > toatl( n, vector<bool>( m, false ) );

        // 考察两列
        for( int i = 0; i < n; ++i )
        {
            dfs( matrix, i, 0, topac );
            dfs( matrix, i, m - 1, toatl );
        }
        // 考察两行
        for( int i = 0; i < m; ++i )
        {
            dfs( matrix, 0, i, topac );
            dfs( matrix, n - 1, i, toatl );
        }

        for( int i = 0; i < n; ++i )
            for( int j = 0; j < m; ++j )
                if( toatl[i][j] && topac[i][j] )
                    res.push_back( make_pair( i,j ) );

        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}