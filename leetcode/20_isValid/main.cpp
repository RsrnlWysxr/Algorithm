#include <iostream>
#include <string>
#include <stack>

using namespace std;





class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for( int i = 0; i < s.size(); ++i )
        {
            if( s[i] == '(' || s[i] == '[' || s[i] == '{' )
            {
                st.push( s[i] );
            }
            else
            {
                if( st.empty() )
                    return false;
                char match = ' ';
                if( s[i] == ')' )
                    match = '(';
                else if( s[i] == ']' )
                    match = '[';
                else
                    match = '{';
                if( st.top() != match )
                    return false;
                else
                    st.pop();
            }
        }
        if( !st.empty() )
            return false;
        return true;
    }
};





int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}