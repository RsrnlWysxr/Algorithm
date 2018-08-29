#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector< vector<bool> > visited;
    int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    void dfs( vector< vector<char> >& grid, int x , int y )
    {
        visited[x][y] = true;
        for( int i = 0; i < 4; ++i )
        {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];
            if( inArea( grid, newx, newy ) && grid[newx][newy] == '1' && !visited[newx][newy] )
                dfs( grid, newx, newy );
        }
    }
    bool inArea(vector< vector<char> >& grid, int x , int y )
    {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size();
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        int res = 0;
        if( grid.empty() )
            return res;
        visited = vector< vector<bool> >( grid.size(), vector<bool>( grid[0].size(), false )  );
        for( int i = 0; i < grid.size(); ++i )
        {
            for( int j = 0; j < grid[i].size(); ++j )
                if( !visited[i][j] && grid[i][j] == '1' )
                {
                    res++;
                    dfs( grid, i , j );
                }
        }
        return res;
    }
};


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}