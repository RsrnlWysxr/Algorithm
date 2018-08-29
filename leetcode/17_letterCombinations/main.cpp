#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution
{
private:
    vector<string> res;
    vector<string> stringmap = {
                                "  ",
                                "",
                                "abc",
                                "def",
                                "ghi",
                                "jkl",
                                "mno",
                                "pqrs",
                                "tuv",
                                "wxyz"
                                    };
    // digits为传入的数字字符串
    // index表示当前考察的字符串位置
    // s表示digits[0...index]处理后生成的字符串
    void findString( string digits, int index, string s )
    {
        if( index == digits.size() )
        {
            res.push_back( s );
            return;
        }
        char c = digits[index];     // 取出数字
        string cur = stringmap[ c - '0' ];  // 数字对应的字符串
        for( auto x: cur )      // 每个字符
        {
            string ss = s + x;
            findString( digits, index + 1, ss );
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        if( digits.empty() )
            return res;
        findString( digits, 0, "");
        return res;
    }
};


int main()
{
    string ss = "234";
    auto res = Solution().letterCombinations( ss );
    for( auto x : res)
        cout << x << endl;
    return 0;
}