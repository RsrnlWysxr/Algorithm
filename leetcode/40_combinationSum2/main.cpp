#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution
{
private:
    vector< vector<int> > res;
    bool* used;
    // out保存每一组结果
    // sum记录和
    // index为当前考虑位置
    void findAnswer( vector<int>& candidates, int target, vector<int>& out, int sum, int index )
    {
        if( sum == target )
        {
            cout << " out内元素为 " << endl;
            for( auto x: out  )
                cout << x << " ";
            cout << " \n \n ";
            res.push_back( out );
            return;
        }
        for( int i = index; i < candidates.size(); ++i )
        {
            cout << "当前考察位置: " << i << endl;
            if( i > 0 && candidates[i] == candidates[i-1] && !used[i-1] )
                continue;
            cout << "考察元素: " << candidates[i] << endl;
            sum += candidates[i];
            // 剪枝
            if( sum > target )
            {
                cout << "sum值为: " << sum << "-->越界，剪枝" << endl;
                return;
            }
            cout << "当前的sum值: " << sum << endl;
            out.push_back( candidates[i] );
            used[i] = true;
            cout << "--去下一层--" << endl;
            findAnswer( candidates, target, out, sum, i+1 );
            cout << "--状态复原--" << endl;
            // 回溯
            sum -= candidates[i];
            out.pop_back();
            used[i] = false;
        }
        cout << endl;
        cout << "一轮搜索完毕" << endl;
        cout << endl;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        res.clear();
        if( candidates.empty() )
            return res;
        used = new bool[ candidates.size() ];
        for( int i = 0; i < candidates.size(); ++i )
            used[i] = false;
        // 排序
        sort( candidates.begin(), candidates.end() );
        vector<int> out;
        findAnswer( candidates, target, out, 0, 0 );
        return res;
    }
};


int main()
{
    vector<int> nums = { 10,1,2,7,6,1,5 };
    Solution().combinationSum2( nums, 8 );
    return 0;
}