#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    int res;
    vector<bool> l;     // 列
    vector<bool> lr;    // 主对角线
    vector<bool> rl;    // 副对角线
    void findAnswer( int n, int index, vector<int>& record )
    {
        if( index == n )
        {
            res++;
            return;
        }
        for( int i = 0; i < n; ++i )
        {
            if( !l[i] && !lr[ index + i ] && !rl[ index - i + n - 1 ] )
            {
                record.push_back( i );
                l[i] = true;
                lr[ index + i ] = true;
                rl[ index - i + n - 1 ] = true;

                findAnswer( n, index + 1, record );

                l[i] = false;
                lr[ index + i ] = false;
                rl[ index - i + n - 1 ] = false;
                record.pop_back();
            }
        }
    }
public:
    int totalNQueens(int n)
    {
        res = 0;
        if( n == 0 )
            return res;
        // 初始化
        l = vector<bool>( n, false );
        lr = vector<bool>( 2 * n - 1, false );
        rl = vector<bool>( 2 * n - 1, false );
        vector<int> record;     // 记录行列位置
        findAnswer( n, 0, record );
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}