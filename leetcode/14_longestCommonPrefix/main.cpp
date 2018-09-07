#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string res;
        if( strs.empty() )
            return res;
        int i = 0;
        while( true )
        {
            if( i >= strs[0].size() )
                return res;
            char tmp = strs[0][i];
            for( auto str : strs )
            {
                if( i >= str.size() )
                    return res;
                if( tmp != str[i] )
                    return res;
            }
            res += tmp;
            i++;
        }
    }
};






int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}