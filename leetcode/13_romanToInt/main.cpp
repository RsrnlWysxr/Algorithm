#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Solution
{
private:
    unordered_map<char,int> roman = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
public:
    int romanToInt(string s)
    {
        if( s.empty() )
            return 0;
        int res = 0;
        for( int i = 0; i < s.size(); i++ )
        {
            if( s[i] == 'I' && ( s[i+1] == 'V' || s[i+1] == 'X' ) )
            {
                res += roman[s[i+1]] - roman[s[i]];
                i++;
            }
            else if( s[i] == 'X' && ( s[i+1] == 'L' || s[i+1] == 'C' ) )
            {
                res += roman[s[i+1]] - roman[s[i]];
                i++;
            }
            else if( s[i] == 'C' && ( s[i+1] == 'D' || s[i+1] == 'M' ) )
            {
                res += roman[s[i+1]] - roman[s[i]];
                i++;
            }
            else
            {
                res += roman[s[i]];
            }
        }
        return res;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}