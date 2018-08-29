#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

/*
/// Time Complexity：O(n)
/// Space Complexity: O(n)
//class Solution
//{
//public:
//    bool isPalindrome(string s)
//    {
//        if ( s.empty() )
//            return true;
//        string ss = "";
//        for( char x : s )
//        {
//            if( x >= 'a' && x <= 'z' )
//                ss.push_back(x - 32);
//            else if(  ( x >= '0' && x <= '9' ) || ( x >= 'A' && x <= 'Z' ) )
//                ss.push_back(x);
//        }
//        int l = 0;
//        int r = ss.size() - 1;
//        while( l < r )
//        {
//            if( ss[l] == ss[r] )
//             {
//                 l++;
//                 r--;
//             }
//            else
//                 return false;
//        }
//        return true;
//    }
//};
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int l = 0;
        int r = s.size() - 1;
        while( l < r )
        {
            if( !isalnum(s[l]) )l ++;
            else if( !isalnum(s[r])) r --;
            else if( s[l] != s[r] ) return false;
            else l++,r--;
        }
        return true;
    }
};



int main() {
    string s = "0P";
    cout << Solution().isPalindrome(s) << endl;
    return 0;
}