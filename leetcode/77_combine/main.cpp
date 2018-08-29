#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector< vector<int> > res;
    void findAnswer( int n, int k, int star, vector<int>& out )
    {
        if( out.size() == k )
        {
            res.push_back( out );
            return;
        }
        // 在[i...n]里 找 k - out.size()个元素
        for( int i = star; i <= n - ( k - out.size() ) + 1; ++i )
        {
            out.push_back( i );
            findAnswer( n, k, i + 1, out );
            out.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k)
    {
        res.clear();
        if( n <= 0 || k <= 0 || k > n )
            return res;
        vector<int> out;
        findAnswer( n, k, 1, out );
        return res;
    }
};




int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}