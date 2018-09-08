#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res( numRows, vector<int>() );
        if( numRows == 0 )
            return res;
        res[0].push_back( 1 );
        if( numRows == 1 )
            return res;
        res[1].push_back( 1 );
        res[1].push_back( 1 );
        if( numRows == 2 )
            return res;
        for( int i = 2; i < numRows; ++i  )
        {
            for( int j = 0; j <= i; ++j )
                res[i].push_back( 1 );
            for( int j = 1; j < i; ++j )
                res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
        return res;
    }
};

int main()
{
    Solution().generate( 5 );
    return 0;
}