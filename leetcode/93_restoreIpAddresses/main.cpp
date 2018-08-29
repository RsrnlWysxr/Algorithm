#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
private:
    // n - 点的个数
    void findip( string s, int n, string out, vector<string>& res )
    {
        if( n == 4 )
        {
            if( s.empty() )
                res.push_back( out );
            return;
        }
        for( int k = 1; k < 4; ++k )
        {
            if( s.size() < k )  break;
            int val = stoi(s.substr(0, k));
            if( val > 255 || k != to_string(val).size() ) continue;
            findip( s.substr( k ), n + 1, out + s.substr( 0, k ) + ( n == 3 ? "" : "." ), res );
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        findip( s, 0, "", res );
        return res;
    }
};




int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}