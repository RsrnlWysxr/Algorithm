#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/// Time Complexity: O(?)
/// Space Complexity: O(?)
class Solution
{
private:
    int op(int x)
    {
        int res = 0;
        while(x)
        {
            int t = x % 10;
            res += t * t;
            x /= 10;
        }
        return res;
    }

public:
    bool isHappy(int n)
    {
        unordered_set<int> memo;
        memo.insert(n);
        while( n != 1 )
        {
            n = op(n);
            if( memo.find(n) != memo.end() )
                return false;
            else
            {
                memo.insert(n);
            }
        }
        return true;
    }
};


int main()
{
    cout << Solution().isHappy(2);
    return 0;
}