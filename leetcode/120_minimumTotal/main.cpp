#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution1
{
private:
    vector<vector<int>> memo;
    int findAnswer( vector<vector<int>>& triangle, int m, int index )
    {
        if( m == triangle.size() - 1 )
            return triangle[m][index];
        if( memo[m][index] == -1 )
        {
            int left =  findAnswer( triangle, m + 1, index ) + triangle[m][index];
            int right = findAnswer( triangle, m + 1, index + 1 ) + triangle[m][index];
            memo[m][index] = min( left, right );
        }
        return memo[m][index];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        if( triangle.empty() )
            return 0;
        for( int i = 0; i < triangle.size(); ++i )
        {   memo.push_back( vector<int>() );
            for (int j = 0; j < triangle[i].size(); ++j)
                memo[i].push_back( -1 );
        }
        return findAnswer( triangle, 0, 0 );
    }
};
class Solution3
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<int> memo = triangle.back();
        for( int i = triangle.size() - 2 ; i >= 0; --i )
            for( int j = 0; j <= i; j++ )
                memo[j] = min( memo[j],memo[j+1] ) + triangle[i][j];
        return memo[0];
    }
};

class Solution2
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<vector<int>> memo;
        // 初始化
        for( int i = 0; i < triangle.size(); ++i )
        {   memo.push_back( vector<int>() );
            for (int j = 0; j < triangle[i].size(); ++j)
                memo[i].push_back( -1 );
        }

        // 初始条件
        for( int j = 0; j < triangle[triangle.size()-1].size(); j++ )
            memo[triangle.size()-1][j] = triangle[triangle.size()-1][j];

        // 动态规划
        for( int i = triangle.size() - 2; i >= 0; --i )
        {
            for( int j = 0; j <= i; j++ )
            {
                memo[i][j] = max( memo[i+1][j] + triangle[i][j], memo[i+1][j+1] + triangle[i][j] );
            }
        }
        return memo[0][0];
    }
};


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}