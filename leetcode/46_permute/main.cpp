#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
 * 输入: [1,2,3]
 * 输出:
 *  [
    [1,2,3],
    [1,3,2],
    [2,1,3],
    [2,3,1],
    [3,1,2],
    [3,2,1]
 *  ]
 */

class Solution
 {

private:
     vector<bool> used;
     void findAnswer( vector<int> nums, vector<int> out, int index, vector< vector<int> >& res )
     {
         if( nums.size() == index )
         {
             res.push_back( out );
             return;
         }
         for( int i = 0; i < nums.size(); ++i )
         {
             if( !used[i])
             {
                 out.push_back( nums[i] );
                 used[i] = true;
                 findAnswer( nums, out, index + 1, res );
                 out.pop_back();
                 used[i] = false;
             }
         }
     }
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector< vector<int> > res;
        if( nums.empty() )
            return res;
        vector<int> out;
        used = vector<bool>( nums.size(), false );
        findAnswer( nums, out, 0, res );
        return res;
    }
};







int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}