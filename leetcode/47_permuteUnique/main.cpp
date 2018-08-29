#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<bool> used;
    vector< vector<int> > res;

    void findAnswer( vector<int>& nums, int indxe, vector<int>& out )
    {
        if( indxe == nums.size() )
        {
            res.push_back( out );
            return;
        }
        for( int i = 0; i < nums.size(); ++i )
        {
            if( !used[i] )
            {
                if( i > 0 && nums[i] == nums[i-1] && !used[i-1] )
                    continue;

                out.push_back( nums[i] );
                used[i] = true;

                findAnswer( nums, indxe + 1, out );

                out.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        res.clear();
        if( nums.empty() )
            return res;
        used = vector<bool>( nums.size(), false );
        sort( nums.begin(), nums.end() );
        vector<int> out;
        findAnswer( nums, 0, out );
        return res;
    }
};




int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}