#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/// 使用哈希查找表
/// 时间复杂度： O(n) 字符串长度视为定值
/// 空间复杂度： O(n)
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> record;       // 字母异位词中的一个 --> 字母异位词数组
        for( auto str : strs )
        {
            string tmp = str;
            sort( tmp.begin(), tmp.end() );
            record[tmp].push_back( str );
        }
        for( auto x : record )
            res.push_back( x.second );
        return res;
    }
};

int main() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = Solution().groupAnagrams( strs );
    for( auto x : res )
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}