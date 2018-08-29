#include <iostream>
#include <vector>
using namespace std;


//class Solution
//{
//public:
//    int removeElement(vector<int>& nums, int val)
//    {
//        int k = 0;
//        int count = 0;
//        for( int i = 0; i < nums.size(); ++i )
//        {
//            if( nums[i] != val )
//                nums[k++] = nums[i];
//            else
//                count++;
//        }
//        return nums.size() - count;
//    }
//};
//class Solution
//{
//public:
//    int removeDuplicates(vector<int>& nums)
//    {
//        int k = 0;
//        int count = 0;
//        for( int i = 1; i < nums.size(); ++i )
//        {
//            if( nums[k] != nums[i] )
//                nums[++k] = nums[i];
//            else
//                count++;
//        }
//        return nums.size() - count;
//    }
//};
class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if( nums.empty() )
            return 0;
        int k = 0;  // 指向当前对比的元素
        int j = 0;  // 记录一个元素重复的次数
        for( int i = 1; i < nums.size(); ++i )
        {
            if( nums[k] == nums[i] )
                j++;
            else if( nums[k] != nums[i] && j >= 1 )
            {
                nums[++k] = nums[k];
                nums[++k] = nums[i];
                j = 0;
            }
            else if ( nums[k] != nums[i] )
                nums[++k] = nums[i];
            if ( i == nums.size() - 1 && j >= 1 )
                nums[++k] = nums[k];
        }
        return k+1;
    }
};




int main() {
    vector<int> nums{1,1,1,1,2,2,3};
    int k = Solution().removeDuplicates(nums);
    for(int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}