#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if( prices.empty() )
            return 0;
        vector<int> sdp( prices.size(), 0 );
        vector<int> bdp( prices.size(), INT_MIN );
        bdp[0] = -prices[0];
        for( int i = 0; i < prices.size(); ++i )
        {
            sdp[i] = max( sdp[i-1], bdp[i-1] + prices[i] );
            if( i >= 2 )
                bdp[i] = max( bdp[i-1], sdp[i-2] - prices[i] );
            else
                bdp[i] = max( bdp[i-1], -prices[i] );
        }
        return sdp[prices.size()-1];
    }
};




int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}