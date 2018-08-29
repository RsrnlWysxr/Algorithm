#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> memo( m , vector<int>( n, 0 ) );
        for( int i = 0; i < strs.size(); ++i )
        {
            int s1 = 0;
            int s0 = 0;
            for( auto c : strs[i] )
                if( c == '0' )
                    s0++;
                else
                    s1++;
            for( int u = m; u >= s0; u-- )
                for( int v = n; v >= s1; v-- )
                    memo[u][v] = max( memo[u][v], memo[u-s0][v-s1] + 1 );
        }
        return memo[m][n];
    }
};




int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}