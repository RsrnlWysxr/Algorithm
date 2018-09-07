#include <iostream>

using namespace std;


class Solution
{
public:
    int reverse(int x)
    {
        long res = 0;
        while( x != 0 )
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if( res > INT32_MAX || res < INT32_MIN )
            return 0;
        return (int)res;
    }
};



int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}