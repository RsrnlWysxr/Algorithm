#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/// Time compexity: O(n)
/// Space compexity: O(n)

class Solution
{
public:
    vector<int> intersection( vector<int>& nums1, vector<int>& nums2 )
    {
        unordered_set<int> record( nums1.begin(),nums1.end() );
        unordered_set<int> res;
        for( auto x : nums2 )
            if( record.find( x ) != record.end() )
                res.insert( x );
        return vector<int>( res.begin(), res.end() );
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}