#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;



class Solution
{
private:
    bool isSame( string word1, string word2 )   // 单词长度相等
    {
        int diff = 0;
        for( int i = 0 ; i < word1.size() ; ++ i )
        {
            if( word1[i] != word2[i] )
                diff++;
            if( diff > 1 )
                return false;
        }
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        // 使用wordList建图
        // 求beginWord->endWord最短路径

        // 结尾单词在字典中的位置
        auto end = find( wordList.begin(), wordList.end(), endWord ) - wordList.begin();
        if( end == wordList.size() )
            return 0;

        // 初始单词在字典中的位置
        auto begin = find( wordList.begin(), wordList.end(), beginWord ) - wordList.begin();
        if( begin == wordList.size() )
            wordList.push_back( beginWord );

        int n = wordList.size();
        // 邻接矩阵
        vector<vector<bool>> g( n , vector<bool>( n,false ) );
        // 使用word初始化图
        for( int i = 0; i < n ; ++i )
        {
            for( int j = 0; j < i; ++j )
                g[i][j] = g[j][i] = isSame( wordList[i], wordList[j] );
        }

        // bfs
        queue<int> q;       // int对应wordList的索引
        vector<int> step( n, 0 );       // 对应步数,也可用作是否已访问

        q.push( begin );
        step[begin] = 1;

        while( !q.empty() )
        {
            auto cur = q.front();
            q.pop();
            // 迭代q的邻边
            for( int i = 0; i < n; ++i )
            {
                if( step[i] == 0 && g[cur][i] )
                {
                    if( i == end )
                        return step[cur] + 1;
                    q.push( i );
                    step[i] = step[cur] + 1;
                }
            }
        }
        return 0;
    }
};








int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}