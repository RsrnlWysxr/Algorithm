#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int res = 0;
        int l = g.size();
        int r = s.size();
        if( l == 0 || r == 0 )
            return res;

        sort( g.begin(), g.end(), greater<>() );
        sort( s.begin(), s.end(), greater<>() );

        int ll = 0;
        int rr = 0;
        while( ll < l && rr < r )
        {
            if( s[rr] >= g[ll] )
                res++, ll++, rr++;
            else
                ll++;
        }
        return res;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}