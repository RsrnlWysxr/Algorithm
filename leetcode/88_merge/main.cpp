#include <iostream>
#include <vector>
using namespace std;

/// Time Complexity: O(n + m)
/// Space Complexity: O(m)
/*
 * class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if( m != 0 )
        {
            int nums1_copy[m];
            for (int i = 0; i < m; ++i)
            {
                nums1_copy[i] = nums1[i];
            }
            int l = 0;      // 指向nums1  [0,m)
            int r = 0;      // 指向nums2  [0,n)
            for (int k = 0; k < m + n; ++k)
            {
                if (r >= n)
                    nums1[k] = nums1_copy[l++];
                else if (l >= m)
                    nums1[k] = nums2[r++];
                else if (nums1_copy[l] < nums2[r])
                    nums1[k] = nums1_copy[l++];
                else
                    nums1[k] = nums2[r++];
            }
        }
        else
        {
            for( int i = 0; i < n; ++i )
                nums1[i] = nums2[i];
        }
    }
};
 */
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m - 1, j = n - 1, index = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            nums1[index--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        while (j >= 0)
            nums1[index--] = nums2[j--];

    }
};




int main()
{
    vector<int> nums1{1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2{2,5,6};
    int n = 3;
    Solution().merge(nums1,m,nums2,n);
    for(int x : nums1)
        cout << x << " ";
}