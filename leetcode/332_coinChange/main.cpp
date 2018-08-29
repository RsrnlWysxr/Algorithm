#include <iostream>
#include <vector>

using namespace std;

class Solution1
{
private:
    vector<int> memo;
    int max_amount;
    int findAnswer( vector<int>& coins, int amount )
    {
        if( amount == 0 )
            return 0;
        if( memo[amount] == -1 )
        {
            int res = max_amount;
            for( auto x: coins )
                if( amount - x >= 0 )
                    res = min( res, 1 + findAnswer( coins, amount - x ) );
            memo[amount] = res;
        }
        return memo[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount)
    {
        max_amount = amount + 1;
        memo = vector<int>( amount+1, -1 );
        int res = findAnswer( coins, amount );
        return res == max_amount ? -1 : res;
    }
};

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> memo( amount + 1, amount + 1 );
        memo[0] = 0;
        for( int i = 1; i <= amount; ++i )
            for( int j = 0; j < coins.size(); ++j )
                if( i - coins[j] >= 0 )
                    memo[i] = min( memo[i], 1 + memo[ i - coins[j] ] );
        return memo[amount]  == amount + 1 ? -1 : memo[amount];
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}