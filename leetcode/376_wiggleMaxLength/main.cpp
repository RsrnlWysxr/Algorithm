#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        int n = nums.size();
        if( n == 0 )
            return 0;
        vector< pair< int, int > > memo( n, make_pair( 0, 1 ) );
        for( int i = 1; i < n; ++i )
            for( int j = 0; j < i; ++j )
                if( nums[i] != nums[j] && memo[j].first * ( nums[i] - nums[j] ) <= 0 && memo[i].second < memo[j].second + 1 )
                    memo[i] = make_pair( nums[i] - nums[j], memo[j].second + 1 ) ;
        for( int i = 0; i < n; ++i )
            cout << nums[i] << ":\t" << memo[i].first << "," << memo[i].second << endl;
        int res = 0;
        for( auto x: memo )
            res = max( res, x.second );
        return res;
    }
};



int main()
{
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    cout <<  Solution().wiggleMaxLength( nums );
    return 0;
}