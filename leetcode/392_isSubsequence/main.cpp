#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int s_l = s.size();
        int t_l = t.size();
        if( s_l == 0  )
            return true;
        if( t_l == 0 )
            return false;

        int s_i = 0;
        int t_i = 0;
        while( s_i < s_l && t_i < t_l )
        {
            if( s[s_i] == t[t_i] )
                s_i++, t_i++;
            else
                t_i++;
        }
        return s_i == s_l;
    }
};


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}