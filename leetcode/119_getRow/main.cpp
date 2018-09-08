#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res( rowIndex+1, 1 );
        if( rowIndex == 0 )
            return res;
        for( int i = 2; i <= rowIndex; ++i )
        {
            for( int j = i - 1; j >= 1; --j )
            {
                res[j] = res[j-1] + res[j];
            }
        }
        return res;
    }
};


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}