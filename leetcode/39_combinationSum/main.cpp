#include <iostream>
#include <vector>

using namespace std;


class Solution
{
private:
    vector< vector<int> > res;
    void findAnswer( vector<int>& nums, int target, int star, vector<int>& out, int sum )
    {
        if( sum == target )
        {
            res.push_back( out );
            return;
        }
        for( int i = star; i < nums.size(); ++i )
        {
            sum += nums[i];
            if( sum > target )
            {
                sum -= nums[i];
                continue;
            }
            out.push_back( nums[i] );
            findAnswer( nums, target, i, out, sum );
            out.pop_back();
            sum -= nums[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        res.clear();
        if( candidates.empty() )
            return res;
        vector<int> out;
        findAnswer( candidates, target, 0, out, 0 );
        return res;
    }
};



int main() {
    vector<int> nums = { 2, 3, 6, 7 };
    Solution().combinationSum( nums, 7 );
    return 0;
}