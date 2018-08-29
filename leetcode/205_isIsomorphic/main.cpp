#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> map(256,-1);
        vector<bool> mapped(256,false);

        for( int i = 0; i < s.size(); ++i )
        {
            if( map[s[i]] == -1 )
            {
                if( mapped[t[i]] )
                    return false;
                map[s[i]] = t[i];
                mapped[t[i]] = true;
            }
            else if( map[s[i]] != t[i] )
                return false;
        }
        return true;
    }
};


int main()
{
    string s = "egg", t = "add";
    cout << Solution().isIsomorphic( s, t );
}