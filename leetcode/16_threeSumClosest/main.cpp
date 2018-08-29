#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

/// Sorting + Two Pointers
/// Time Complexity: O(nlogn) + O(n^2)
/// Space Complexity: O(1)
class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        assert( nums.size() >= 3 );
        sort( nums.begin(), nums.end() );
        int diff = abs( nums[0] + nums[1] + nums[2] - target );
        int res = nums[0] + nums[1] + nums[2];
        for( int i = 0; i < nums.size(); ++i )
        {
            int l = i + 1;
            int r = nums.size() - 1;
            int t = target - nums[i];
            while( l < r )
            {
                if( nums[l] + nums[r] == t )
                    return nums[i] + nums[l] + nums[r];
                else
                {
                    if( abs( nums[l] + nums[r] - t ) < diff )
                    {
                        diff = abs( nums[l] + nums[r] - t );
                        res = nums[i] + nums[l] + nums[r];
                    }
                    else if( nums[l] + nums[r] < t )
                        ++l;
                    else
                        --r;
                }
            }
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}