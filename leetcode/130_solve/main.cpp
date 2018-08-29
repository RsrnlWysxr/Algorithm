#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution
{
private:
    int m, n;
    vector< vector<bool> > visited;
    int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
    bool bfs( vector< vector<char> >& board, vector< pair< int, int > > &record, int x , int y )
    {
        bool ret = true;

        visited[x][y] = true;
        queue< pair< int, int > > q;

        q.push( make_pair( x, y ) );
        while( !q.empty() )
        {
            auto cur = q.front();
            q.pop();
            record.push_back( cur );
            for( int i = 0; i < 4; ++i )
            {
                int newx = cur.first + dir[i][0];
                int newy = cur.second + dir[i][1];
                if( !inArea( newx, newy ) )
                    ret = false;
                else if( board[newx][newy] == 'O' && !visited[newx][newy] )
                {
                    q.push( make_pair( newx,newy ) );
                    visited[newx][newy] = true;
                }
            }
        }
        return ret;
    }
    bool inArea( int x , int y )
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    void solve(vector<vector<char>>& board)
    {
        m = board.size();
        if( m == 0 )
            return;
        n = board[0].size();
        if( n == 0 )
            return;
        vector< pair< int , int > > record;
        visited = vector< vector<bool> >( m, vector<bool>( n, false ) );
        for( int i = 0; i < m; ++i )
        {
            for( int j = 0; j < n; ++j )
            {
                if( board[i][j] == 'O' && !visited[i][j] )
                {
                    record.clear();
                    if( bfs( board, record, i, j ) )
                        for( int k = 0; k < record.size(); ++k )
                            board[record[k].first][record[k].second] = 'X';
                }
            }
        }
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}