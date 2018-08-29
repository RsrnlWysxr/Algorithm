#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Time Compexity: O(n)
/// Space Compexity: O(1)
class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int l = 0;
        int r = height.size() - 1;
        int area = -1;
        while( l < r )
        {
            area = max ( area, (r - l) * min( height[r], height[l] ));
            if( height[l] < height[r] ) l++;
            else if ( height[l] >= height[r] ) r--;
        }
        return area;
    }
};

int main() {
    vector<int> height{1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(height);
    return 0;
}