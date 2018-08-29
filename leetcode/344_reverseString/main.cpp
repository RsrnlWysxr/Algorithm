#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


/// Time Compexity: O(n)
/// Time Compexity: O(1)
class Solution
{
public:
    string reverseString(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        while( l < r )
        {
            swap( s[l++], s[r--] );
        }
        return s;
    }
};

int main()
{
    cout << Solution().reverseString("abb");
    return 0;
}