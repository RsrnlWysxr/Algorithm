#include <iostream>
#include <string>

using namespace std;


class Solution
{
private:
    string vowels = "aeiouAEIOU";
    bool isVowels( char s )
    {
        if( vowels.find(s) != string::npos  )
            return true;
        else
            return false;
    }
public:
    string reverseVowels(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        while( l < r )
        {
            if( !isVowels(s[l])) l++;
            else if( !isVowels(s[r])) r--;
            else
                swap( s[l++], s[r--] );
        }
        return s;
    }
};


int main() {
    cout << Solution().reverseVowels("hello");
    return 0;
}