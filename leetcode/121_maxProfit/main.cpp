#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if( prices.empty() )
            return 0;

        int minprice = prices[0];
        int res = 0;
        for( int i = 1; i < prices.size(); ++i )
        {
            res = max( res, prices[i] - minprice );
            minprice = min( minprice, prices[i] );
        }
        return res;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}