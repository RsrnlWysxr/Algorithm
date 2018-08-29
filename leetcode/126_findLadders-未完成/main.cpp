#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;



class Solution
{
private:
    bool isSame( string word1, string word2 )
    {
        int diff = 0;
        for( int i = 0; i < word1.size(); ++i )
        {
            if( word1[i] != word2[i] )
                diff++;
            if( diff > 1 )
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<vector<string>> res;
        auto end = find( wordList.begin(), wordList.end(), endWord ) - wordList.begin();
        if( end == wordList.size() )
            return res;
        auto begin = find( wordList.begin(), wordList.end(), beginWord ) - wordList.begin();
        if( begin == wordList.size() )
            wordList.push_back( beginWord );

        // 建立邻接矩阵
        int n = wordList.size();
        vector<vector<int>> g;      // int 对应索引
        for( int i = 0; i < n; ++i )
            for( int j = 0; j < i; ++j )
                g[i][j] = g[j][i] = isSame( wordList[i], wordList[j] );

        queue<int> q;
        vector<bool> visited( n, false );
        vector<int> from
        q.push( begin );

        while( !q.empty() )
        {
            int cur = q.front();
            q.pop();
            // 遍历当前节点所有邻边
            for( int i = 0; i < n; ++i )
            {
                if()
            }
        }


    }
};







int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}