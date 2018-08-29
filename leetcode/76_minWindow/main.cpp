#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
/// Time Compexity: O(n)
/// Space Compexity: O(1)
class Solution
{
private:
    bool contains( const vector<int> &freq_t, const vector<int> &freq_s )
    {
        for( int i = 0; i < 128; i++ )
        {
            if( freq_t[i] != 0 )
            {
                if (freq_t[i] > freq_s[i])
                    return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t)
    {
        string res = "";
        int ll = 0;     // 记录找到的最小子串左边界
        int rr = s.size();     // 记录找到的最小子串的右边界
        int l = 0, r = -1;  // 滑动窗口[l...r]
        vector<int> freq_t (128,0);
        vector<int> freq_s (128,0);
        for( char x : t )
        {
            freq_t[x]++;
        }
        while( l < s.size() )
        {
            // 更新窗口
            if(  r + 1 < s.size() && !contains( freq_t, freq_s ) )
                freq_s[s[++r]]++;
            else
                freq_s[s[l++]]--;
            if( contains( freq_t, freq_s  ) )
                if( rr - ll > r - l )
                    ll = l, rr = r;
        }
        if( rr == s.size() )
            return res;
        else
            for( int i = ll; i <= rr; ++i )
                res.push_back( s[i] );
        return res;
    }
};
 */


class Solution
{
public:
    string minWindow(string s, string t)
    {
        string res = "";
        int ll = 0;     // 记录找到的最小子串左边界
        int rr = s.size();     // 记录找到的最小子串的右边界
        int cMatch = 0;         // 记录与T中匹配字母的个数
        int l = 0, r = -1;  // 滑动窗口[l...r]
        vector<int> freq_t (128,0);
        vector<int> freq_s (128,0);
        for( char x : t )
        {
            freq_t[x]++;
        }
        while( l < s.size() )
        {
            if( r + 1 < s.size() && cMatch < t.size() )
            {
                freq_s[s[++r]]++;
                if( freq_s[s[r]] <= freq_t[s[r]] )
                    cMatch++;
            }
            else    // cMatch <= t.size()
            {
                if( cMatch == t.size() && r - l < rr - ll )
                    ll = l, rr = r;
                freq_s[s[l++]]--;
                if( freq_s[s[l - 1]] < freq_t[s[l - 1]] )
                    cMatch--;
            }
        }
        if( rr == s.size() )
            return res;
        else
            for( int i = ll; i <= rr; ++i )
                res.push_back( s[i] );
        return res;
    }
};

int main() {
    string S = "ADOBECODEBANC";
    string T = "ABC";
    cout << Solution().minWindow(S,T);
    return 0;
}