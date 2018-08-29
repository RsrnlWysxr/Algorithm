#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// Time complexity: O(n)
/// Space complexity: O(n)
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int,int> record;
        vector<int> res;
        for( auto x : nums1 )
            record[x]++;
        for( auto x : nums2 )
        {
            if( record[x] > 0 )
            {
                res.push_back(x);
                record[x]--;
            }
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}