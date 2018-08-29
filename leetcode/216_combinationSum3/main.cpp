#include <iostream>
#include <vector>

using namespace std;


class Solution
{
private:
    vector< vector<int> > res;
    int target;
    int depth;
    // k表示递归深度
    // sum记录和
    // out记录有用输出
    // data表示[1...9]
    // index表示考察位置
    void findAnswer( int k, int sum, vector<int>& out, vector<int>& data, int index )
    {
        if( k == depth && sum == target )
        {
            res.push_back( out );
            return;
        }
        for( int i = index; i < data.size(); ++i )
        {
            sum += data[i];
            if( sum > target )
                return;
            out.push_back( data[i] );
            findAnswer( k+1, sum, out, data, i+1 );
            out.pop_back();
            sum -= data[i];
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        res.clear();
        depth = k;
        target = n;
        if( n <= 0 || k <= 0 )
            return res;
        vector<int> data = { 1,2,3,4,5,6,7,8,9 };
        vector<int> out;
        findAnswer( 0, 0, out, data, 0 );
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}