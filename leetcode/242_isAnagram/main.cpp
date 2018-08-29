#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


/*
/// Time Complexity: O(n)
/// Time Complexity: O(n)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char,int> record;
        for( auto x : s )
            record[x]++;
        for( auto x: t )
        {
            if( record[x] > 0 )
                record[x]--;
            else
                return false;
        }
        for( auto x : record )
            if( x.second > 0 )
                return false;
        return true;
    }
};
 */
/// Time Complexity: O(n)
/// Time Complexity: O(n)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char,int> m_s;
        unordered_map<char,int> m_t;
        for( auto x : s )
            m_s[x]++;
        for( auto x: t )
            m_t[x]++;
        for(  int i = 'a'; i < 'z'; i++ )
        {
            if( m_s[i] != m_t[i] )
                return false;
        }
        return true;
    }
};

int main()
{
    Solution().isAnagram("ab","a");
    return 0;
}