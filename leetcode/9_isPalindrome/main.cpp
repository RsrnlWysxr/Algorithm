#include <iostream>
using namespace std;

class Solution1
{
public:
    bool isPalindrome(int x)
    {
        if( x < 0 )
            return false;
        int tmp = x;
        int res = 0;
        while( x != 0 )
        {
            res = res * 10 + x % 10;
            x /= 10;
        }

        return tmp == res;
    }
};

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if( x < 0 || ( x % 10 == 0 && x != 0 ) )
            return false;
        int res = 0;
        while( x > res )
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == x || res / 10 == x ;
    }
};

int main()
{
    Solution().isPalindrome( 121 );
    return 0;
}