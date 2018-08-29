#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector< vector<int> > res;
    vector<bool> used;
    void findAnswer( vector<int>& nums, vector<int> out, int index )
    {
        for( int i = index; i < nums.size(); ++i )
        {
            if( i > 0 && nums[i] == nums[i-1] && !used[i-1] )
                continue;
            out.push_back( nums[i] );
            used[i] = true;
            res.push_back( out );
            findAnswer( nums, out, i + 1 );
            out.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        res.clear();
        res.push_back( vector<int>() );
        if( nums.empty() )
            return res;
        sort( nums.begin(), nums.end() );
        used = vector<bool>( nums.size(), false );
        vector<int> out;
        findAnswer( nums, out, 0 );
        return res;
    }
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}