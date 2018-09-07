#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int i;
        for( i = 0; i < nums.size(); ++i )
        {
            if( target <= nums[i] )
                return i;
        }
        return i + 1;
    }
};


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}