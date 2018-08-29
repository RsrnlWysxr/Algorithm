#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    string frequencySort(string s)
    {
        string res = "";
        if( s.empty() )
            return res;
        unordered_map<char,int> si;
        for( int i = 0; i < s.size(); ++i )
            si[s[i]]++;
        multimap<int,char,greater<int>> ic;
        for( auto it = si.begin(); it != si.end(); ++it )
        {
            ic.insert( make_pair( it->second,it->first ) );
        }
        for( auto it = ic.begin(); it != ic.end(); ++it )
        {
            for( int i = 0; i < it->first; ++i )
            {
                res.push_back( it->second );
            }
        }
        return res;
    }
};


int main() {
    cout << Solution().frequencySort( "tree" );
    return 0;
}