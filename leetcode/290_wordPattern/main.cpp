#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <sstream>

using namespace std;
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution
{
private:
    void vailString( string str ,vector<string>& s)
    {
        // 处理str，分隔单词
        istringstream ss( str );    // str初始化输入缓存流
        string tmpStr;      // 暂存
        while( ss >> tmpStr )
            s.push_back( tmpStr );
    }

public:
    bool wordPattern(string pattern, string str)
    {
        unordered_map<char,string> record_pattern;
        unordered_map<string,char> record_str;
        vector<string> s;
        vailString( str,s );

        if( pattern.size() != s.size() )
            return false;

        for( int i = 0; i < pattern.size(); i++ )
        {
            if( record_pattern.find( pattern[i] ) == record_pattern.end()  )
            {
                if( record_str.find( s[i] ) != record_str.end() )
                    return false;
                record_pattern.insert( make_pair( pattern[i], s[i] ) );
                record_str.insert( make_pair( s[i], pattern[i] ) );
            }
            else
            {
                assert( record_pattern.find( pattern[i] ) != record_pattern.end()  );
                if( record_pattern[ pattern[i] ] == s[i] && record_str[ s[i] ] == pattern[i] )
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    cout << Solution().wordPattern("abba","dog dog dog dog");
    return 0;
}