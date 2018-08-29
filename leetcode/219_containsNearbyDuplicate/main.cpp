#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        // [0...k] --> k+1个元素
        unordered_set<int> record;  // 最多k+1个元素
        for( int i = 0; i < nums.size(); ++i )
        {
            if( record.find( nums[i] ) != record.end() )
                return true;
            record.insert( nums[i] );
            if( record.size() == k + 1 )
                record.erase( nums[i - k] );
        }
        return false;
    }
};



int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}