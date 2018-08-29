#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * 输入: "aab"
 * 输出:
 *  [
 *  ["aa","b"],
 *  ["a","a","b"]
 *   ]
 */

class Solution {
private:
    // s表示还未处理的字符串
    // out保存最终为回文串的字符串
    // res保存最终为回文串的字符串数组
    void findanswer( string s, vector<string> out, vector< vector<string> >& res )
    {
        if( s.empty() )
        {
            res.push_back( out );
            return;
        }
        // 每次至少取一个字母
        // k表示长度
        for( int k = 1; k <= s.size(); ++k )
        {
            string tmp = s.substr( 0, k );
            if( isRetrunString( tmp ) )
            {
                out.push_back( tmp );
                findanswer( s.substr( k ), out, res ) ;
                out.pop_back();
            }
        }
    }
    //判断一个字符串是否为回文串
    bool isRetrunString( string s )
    {
        int n = s.size();
        if( n == 0 || n == 1)
            return true;
        for( int i = 0; i < n / 2; ++i )
        {
            if( s[i] != s[ n - 1 - i] )
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector< vector<string> > res;
        if( s.empty() )
            return res;
        vector<string> out;
        findanswer( s, out, res );
        return res;
    }
};



int main()
{
    Solution().partition( "aab" );
    return 0;
}