#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};




class Solution {
private:
    static bool compare( const Interval& a, const Interval& b )
    {
        if( a.end == b.end )
            return a.start < b.start;
        return a.end < b.end;
    }
public:
    int eraseOverlapIntervals(vector<Interval>& intervals)
    {
        if( intervals.size() == 0 )
            return 0;
        sort( intervals.begin(), intervals.end(), compare );

        int res = 1;
        int pre = 0;
        for( int i = 1; i < intervals.size(); ++i )
            if( intervals[i].start >= intervals[pre].end )
                pre = i, res++;

        return intervals.size() - res;
    }
};




int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}