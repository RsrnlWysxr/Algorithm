#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector< vector<bool> > visited;
    int dir[4][2] ={
                        {-1,0},
                        {0,1},
                        {1,0},
                        {0,-1}
                            };
    bool findAnwser( vector<vector<char>>& board, string word, int index, int x, int y )
    {
        if( index == word.size() - 1 )
            return board[x][y] == word[index];
        if( board[x][y] == word[index] )
        {
            visited[x][y] = true;
            for( int i = 0; i < 4; ++i )
            {
                int newx = x + dir[i][0];
                int newy = y + dir[i][1];
                if( inArea( board, newx, newy ) && !visited[newx][newy] )
                    if( findAnwser( board, word, index + 1, newx, newy ) )
                        return true;
            }
            visited[x][y] = false;
        }
        return false;
    }
    bool inArea( vector<vector<char>>& board, int x , int y )
    {
        return x < board.size() && x >= 0 && y < board[x].size() && y >= 0;
    }
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if( board.empty() )
            return false;
        visited = vector< vector<bool> >( board.size(), vector<bool>( board[0].size(), false )  );
        for( int i = 0; i < board.size(); ++i )
            for( int j = 0; j < board[i].size(); ++j )
                if( findAnwser( board, word, 0, i, j ) )
                    return true;
        return false;
    }
};




int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}