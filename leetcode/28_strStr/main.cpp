#include <iostream>
#include <string>

using namespace std;

class Solution1
{
public:
    int strStr(string haystack, string needle)
    {
        int i;      // 指向haystack
        int j;      // 指向needle
        int M = haystack.size();
        int N = needle.size();
        for( i = 0, j = 0; i < M && j < N; i++ )
        {
            if( needle[j] == haystack[i] )
                j++;
            else
            {
                i -= j;
                j = 0;
            }
        }
        if( j == N ) return i - N;
        else
            return -1;
    }
};

class Solution
{
private:
    int* next;
    void countnext( string needle )
    {
        int i = 0;
        int k = -1;
        next[0] = -1;
        while( i < needle.size() - 1 )
        {
            if( k == -1 || needle[k] == needle[i] )
                next[++i] = ++k;
            else
                k = next[k];
        }
    }
public:
    int strStr(string haystack, string needle)
    {
        if( needle.empty() )
            return 0;
        next = new int[needle.size()];
        countnext( needle );
        int i = 0;
        int j = 0;
        while( i < (int)haystack.size() && j < (int)needle.size() )
        {
            if( j == -1 || haystack[i] == needle[j] )
            {
                i++;
                j++;
            }
            else
                j = next[j];
        }
        if( j == needle.size() )
            return i-j;
        return -1;
    }
};



int main()
{
    cout << Solution().strStr( "mississippi","issipi" );
    return 0;
}