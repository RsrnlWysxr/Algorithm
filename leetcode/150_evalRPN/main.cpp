#include <iostream>
#include <stack>
#include <cassert>
#include <vector>
#include <sstream>

using namespace std;



class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> num;
        for( auto& x: tokens )
        {
            if( x != "+" && x != "-" && x != "*" && x != "/" )
            {
//                int in;
//                istringstream ss( x );
//                ss >> in;
//                num.push( in );
                num.push( atoi(x.c_str()) );
            }
            else
            {
                int l;
                int r;
                if( num.size() < 2 )
                    break;
                r = num.top();
                num.pop();
                l = num.top();
                num.pop();
                if( x == "+" )
                    num.push( l + r );
                else if( x == "-" )
                    num.push( l - r );
                else if( x == "*" )
                    num.push( l * r );
                else
                    num.push( l / r );
            }
        }
        return num.top();
    }
};



int main()
{
    vector<string> tokens = { "2", "1", "+", "3", "*" };
    Solution().evalRPN( tokens );
    return 0;
}