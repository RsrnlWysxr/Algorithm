#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
    {
        set<long long> record;        // 最多保存k+1个元素，加入新的元素时，删去第一个元素
        for( int i = 0; i < nums.size(); ++i )
        {
            if( record.lower_bound( (long long)nums[i] - (long long)t ) != record.end()
                && *record.lower_bound( (long long)nums[i] - (long long)t ) <= (long long)nums[i] + (long long)t )
                return true;
            record.insert( nums[i] );
            if( record.size() == k + 1 )
                record.erase( nums[i-k] );
        }
        return false;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}