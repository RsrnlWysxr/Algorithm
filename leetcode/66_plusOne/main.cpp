#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int car = 0;        // 进位标识
        int n = digits.size() - 1;
        car = ( 1 + digits[n] ) / 10;
        digits[n] = ( 1 + digits[n] ) % 10;
        for( int i = n - 1; i >= 0; --i )
        {
            int tmp = car + digits[i];
            digits[i] = tmp % 10;
            car = tmp / 10;
        }
        if( car != 0 )
            digits.insert( digits.begin() , car );
        return digits;
    }
};


int main()
{
    vector<int> digits = { 9 };
    Solution().plusOne( digits );
    return 0;
}