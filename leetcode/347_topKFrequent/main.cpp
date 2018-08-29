#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> res;
        if( nums.empty() )
            return res;

        unordered_map<int,int> um;  // 元素->频率
        for( auto x: nums )
            um[x]++;

        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<> > pq;    // 频率->元素
        for( auto x: um )
        {
            if( pq.size() == k )
            {
                if( x.second > pq.top().first )
                {
                    pq.pop();
                    pq.push( make_pair( x.second, x.first ) );
                }
            }
            else
                pq.push( make_pair( x.second, x.first ) );
        }
        while( !pq.empty() )
        {
            res.push_back( pq.top().second );
            pq.pop();
        }
        return res;
    }
};



int main() {
    vector<int> nums = {3,0,1,0};
    auto ret = Solution().topKFrequent( nums, 1 );
    return 0;
}