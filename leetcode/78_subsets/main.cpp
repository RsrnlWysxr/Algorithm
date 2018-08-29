#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector< vector<int> > res;
    void findAnswer( vector<int>& nums, vector<int>& out,  int index )
    {
        for( int i = index; i < nums.size(); ++i )
        {
            out.push_back( nums[i] );
            res.push_back( out );
            findAnswer( nums, out, i+1 );
            out.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        res.clear();
        res.push_back( vector<int>() );
        if( nums.empty() )
            return res;
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