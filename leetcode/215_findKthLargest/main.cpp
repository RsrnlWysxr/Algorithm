#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
/// Quick Sort Partition.
/// Time Complexity:  O(n)
/// Space Complexity: O(1)
class Solution
{
private:
    int findK;
    int k;
    int partition( vector<int>& nums, int l, int r )
    {
        int v = nums[l];
        int i = l + 1;      // >v  [l+1...gt)
        int gt = l + 1;     // <=v  [gt...i)
        for( ; i <= r; ++i )
        {
            if( nums[i] > v )
                swap( nums[i], nums[gt++] );
        }
        swap( nums[l], nums[--gt] );
        return gt;
    }
    void findKthLargest( vector<int>& nums, int l, int r )
    {
        if( l > k || r < k)
            return;
        int p  = partition( nums, l, r );
        if( p < k )
            findKthLargest( nums, p + 1, r );
        if( p > k )
            findKthLargest( nums, l, p - 1 );
        if( p == k )
            findK = p;
        return;
    }


public:
    int findKthLargest(vector<int>& nums, int k)
    {
        if( nums.empty() )
            return 0;
        this->k = k - 1;
        findKthLargest( nums, 0, nums.size() - 1 );
        return nums[findK];
    }
};
 */

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> pq;
        for( int i = 0; i < nums.size(); i++ )
            pq.push(nums[i]);
        for( int i = 0; i < k - 1; i++ )
            pq.pop();
        return pq.top();
    }
};


int main() {
    vector<int> nums{3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << Solution().findKthLargest(nums,k);
    return 0;
}