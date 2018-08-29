#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int,int> eletin;      // key为元素，value为索引
        for( int i = 0; i < nums.size(); ++i )
        {
            int match = target - nums[i];
            if( eletin.find( match ) != eletin.end() )
                return vector<int>{ i, eletin[ match ] };
            else
                eletin[nums[i]] = i;
        }
    }
};

int main() {
    vector<int> nums  {2, 7, 11, 15};
    int target = 9;
    Solution().twoSum( nums, target );
    return 0;
}