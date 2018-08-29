#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution
{
private:
    vector< vector<bool> > ires;
    void findAnswer( int num, int index, vector<bool>& time,int count )
    {
        if( count == num )
        {
//            cout << " now time：" << endl;
//            for( auto x: time )
//                cout << x << " ";
//            cout << endl;
            ires.push_back( time );
        }
        for( int i = index; i < 10; ++i )
        {
            time[i] = true;
            findAnswer( num, i + 1, time, count + 1 );
            time[i] = false;
        }

    }
public:
    vector<string> readBinaryWatch(int num)
    {
        vector<string> res;
        if( num < 0 || num > 10 )
            return res;
        vector<bool> time( 10, false );
        findAnswer( num, 0, time, 0 );
        for( auto x: ires )
        {
            int hour = 0;
            int min = 0;
            for( int i = 0; i < 4; ++i )
            {
                if( x[i] )
                    hour += pow( 2, i );
            }
            for( int i = 4; i < 10; ++i )
            {
                if( x[i] )
                    min += pow( 2, i-4 );
            }
            if( hour >= 12 || min >= 60 )
                continue;
            else if( min > 9 )
                res.push_back( to_string( hour ) + ":" + to_string( min ) );
            else
                res.push_back( to_string( hour ) + ":" + "0" + to_string( min ) );
        }
        return res;
    }
};




int main()
{
    auto res = Solution().readBinaryWatch( 2 );
    for( auto x : res )
        cout << x << ",";
    return 0;
}