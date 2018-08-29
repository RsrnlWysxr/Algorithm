#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
/// Using hash table
/// Sort the array first.
/// Store every different c + d == t first
/// For every different number a and b, try to find a pair (c, d), which a + b + c + d == 0
///
/// Time Complexity: O(nlogn) + O(n^2) + O(n^2*logn)
/// Space Complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int>> res;
        if(n < 4)
            return res;

        sort(nums.begin() , nums.end());

        unordered_map<int, vector<pair<int, int>>> hashtable;
        for(int i = 0 ; i < n - 1 ; i = nextNumberIndex(nums, i))
            for(int j = i + 1 ; j < n ; j = nextNumberIndex(nums, j))
                hashtable[nums[i]+nums[j]].push_back(make_pair(nums[i], nums[j]));

        for( int i = 0 ; i <= n - 4 ; i = nextNumberIndex(nums, i) )
            for (int j = i + 1; j <= n - 3; j = nextNumberIndex(nums, j)) {

                int t = target - nums[i] - nums[j];
                if( nums[j+1] + nums[j+2] > t || nums[n-1] + nums[n-2] < t)
                    continue;

                if(hashtable.find(t) == hashtable.end())
                    continue;

                vector<pair<int,int>>::iterator iter =
                        lower_bound(hashtable[t].begin(), hashtable[t].end(), make_pair(nums[j+1], nums[j+1]));
                for(; iter != hashtable[t].end() ; iter ++)
                    res.push_back({nums[i], nums[j], iter->first, iter->second});
            }

        return res;
    }

private:
    int nextNumberIndex( const vector<int> &nums , int index ){
        for( int i = index + 1 ; i < nums.size() ; i ++ )
            if( nums[i] != nums[index] )
                return i;
        return nums.size();
    }

    int preNumberIndex( const vector<int> &nums , int index ){
        for( int i = index-1 ; i >= 0 ; i -- )
            if( nums[i] != nums[index] )
                return i;
        return -1;
    }
};


void print_vec(const vector<vector<int>>& vec){
    for(const vector<int>& v: vec){
        for(int e: v)
            cout << e << " ";
        cout << endl;
    }
}
 */




class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int size = nums.size();
        if(size < 4)
            return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < size - 3; ++i)         // 外循环，四数之和转化为三数之和
        {
            if(i > 0 && nums[i] == nums[i - 1])     // 如果两个数相等，去重
                continue;
            if(nums[i] + nums[size-1] + nums[size-2] + nums[size-3] < target)   // 由于有序，如果当前数加最后三个数都比target小，那肯定不符合
                continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)  // 如果连续四个数都比target大，后面肯定没有符合要求的情况，直接return
                return res;
            for(int j = i + 1; j < size - 2; ++j) // 内循环三数之和（从第二个数开始，后面每个数都是从前面一个数的后面开始遍历）
            {
                if(j > i + 1 && nums[j] == nums[j - 1])   // 如果两个数相等，去重
                    continue;
                if(nums[i] + nums[j] + nums[size-1] + nums[size-2] < target)  // 前两个数确定，加上最后两个数都比target小，那肯定不符合
                    continue;
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)    //  前两个数确定，如果后面连续两个数和比target大，不符合条件
                    break;
                int left = j + 1, right = size - 1;
                while(left < right)   // 两数之和
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        while(left < right && nums[left] == nums[left - 1])
                            ++left;

                        --right;
                        while(left < right && nums[right] == nums[right + 1])
                            --right;
                    }
                    else if(sum > target)
                        --right;
                    else
                        ++left;
                }
            }
        }
        return res;
    }
};



int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}