#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        bool visited[256]={false};
        int l = 0, r = -1;  // [l...r]窗口
        int length = 0;
        while( l < s.size() )
        {
            if( !visited[s[r+1]] && r + 1 < s.size() )
                visited[s[++r]] = true;
            else
                visited[s[l++]] = false;
            length = max( length, r - l + 1 );
        }
        return length;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}