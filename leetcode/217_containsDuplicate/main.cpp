#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        auto s = new unordered_set<int>();
        if( nums.size() == 1 || nums.size() == 0 )
            return false;
        for( int i = 0; i < nums.size(); i++ )
        {
            if( s->find( nums[i] ) == s->end() )
                s->insert( nums[i] );
            else
                return true;
        }
        return false;
    }
};



int main()
{
    vector<int> nums{1,2,3,1};
    Solution a;
    a.containsDuplicate( nums );
    return 0;
}