#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector< vector< bool > > spa;       // 九宫格
    vector< vector< bool > > l;                   // 列
    vector< vector< bool > > r;                   // 行

    bool dfs( vector<vector<char>>& board, int x, int y )
    {
        if( y > 8 )
        {
            x += 1;
            y = 0;
        }
        if( x > 8 )
            return true;
        if( board[x][y] == '.' )
        {
            for( int k  = 1; k <= 9; ++k )
            {
                if( isVaild( x, y, k ) )
                {
                    set( x, y, k, true );
                    board[x][y] =  char('0' + k);
                    if( dfs( board, x, y + 1 ) )
                        return true;
                    set( x, y, k, false );
                    board[x][y] = '.';
                }
            }
            return false;
        }
        else
        {
            return dfs( board, x, y + 1 );
        }

    }
    int getSp( int x, int y )
    {
        return ( x / 3 ) * 3 + ( y / 3 );
    }
    bool isVaild( int x, int y, int num )
    {
        if( l[y][num] )
            return false;
        if( r[x][num] )
            return false;
        if( spa[getSp( x, y )][num] )
            return false;
        return true;
    }
    void set( int x, int y, int num, bool bo )
    {
        r[x][num] = bo;
        l[y][num] = bo;
        spa[getSp( x, y )][num] = bo;
    }

public:
    void solveSudoku(vector<vector<char>>& board)
    {
        // 初始化
        spa = vector< vector<bool> >( 9, vector<bool>( 10, false ) );
        l = vector< vector<bool> >( 9, vector<bool>( 10, false ) );
        r = vector< vector<bool> >( 9, vector<bool>( 10, false ) );
        for( int i = 0; i < 9; ++i )
        {
            for( int j = 0; j < 9; ++j )
            {
                if( board[i][j] != '.' )
                    set( i, j, board[i][j] - '0', true );
            }
        }
        dfs( board, 0, 0 );
    }
};



int main()
{
    vector<vector<char>> board = {  {'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','.'}
                                };
    Solution().solveSudoku( board );
    for( auto x: board )
    {
        for( auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}