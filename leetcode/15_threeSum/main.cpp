#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


/*
/// use Hash Table
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        unordered_map<int,int> counter;      // 建立由元素到索引的查找表
        for( auto x : nums )
            counter[x]++;

        vector<vector<int>> res;

        if( counter[0] >= 3 )
            res.push_back( { 0, 0, 0 } );

        // 去重
        sort( nums.begin(), nums.end() );
        auto it = unique( nums.begin(), nums.end() );
        nums.erase( it, nums.end() );

        for( int i = 0; i < nums.size(); ++i )
        {
            for( int j = i + 1; j < nums.size(); ++j )
            {
                if( nums[i] * 2 + nums[j] == 0 && counter[ nums[i] ] >= 2 )
                    res.push_back( { nums[i], nums[i], nums[j] } );
                if( nums[i] + nums[j] * 2 == 0 && counter[ nums[j] ] >= 2 )
                    res.push_back( { nums[i], nums[j], nums[j] } );
                int c = 0 - nums[i] - nums[j];
                if( c > nums[j] && counter[c] > 0 )
                    res.push_back( { nums[i], nums[j], c } );
            }
        }
        return res;
    }
};
 */

/// use two pointer
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort( nums.begin(), nums.end() );       // 排序
        vector<vector<int>> res;
        for( int i = 0; i < nums.size(); ++i )  // 固定一个数
        {
            if( nums[i] > 0 )
                break;          // 已经排序，则与后面和不可能为0
            if( i > 0 && nums[i - 1] == nums[i] )   // 相同的数不固定两次
                continue;
            int target = 0 - nums[i];
            // 问题转换为 在有序数组中 查找两数的和
            // 使用对撞指针
            int l = i + 1;
            int r = nums.size() - 1;
            while( l < r )
            {
                if( nums[l] + nums[r] == target )
                {
                    res.push_back( { nums[i], nums[l], nums[r] } );
                    while( l < r && nums[r] == nums[r - 1] )
                        --r;
                    while( l < r && nums[l] == nums[l + 1] )
                        ++l;
                    --r;
                    ++l;
                }
                else if ( nums[l] + nums[r] < target )
                    ++l;
                else
                    --r;

            }
        }
        return res;
    }
};




int main() {
    vector<int> nums { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> vec = Solution().threeSum( nums );
    for ( auto x : vec )
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}