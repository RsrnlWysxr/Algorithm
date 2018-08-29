#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void reversElements( vector<int>& nums, int l, int r )
    {
        while( l < r )
            swap( nums[l++],nums[r--] );
    }
public:
    void rotate( vector<int>& nums, int k )
    {
        auto n = nums.size();
        if( n == k || nums.empty() || k == 0 || n == 1)
            return;
        auto ro = ( k + n ) % n;
        reversElements( nums, 0, n - ro - 1 );
        reversElements( nums, n - ro , n - 1 );
        reversElements( nums, 0, n - 1 );
    }
};

int main()
{
    vector<int> nums {1,2};
    int k = 3;
    Solution a;
    a.rotate(nums,k);
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    return 0;
}