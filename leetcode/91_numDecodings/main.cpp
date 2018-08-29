#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0 || s[0]=='0') return 0;
        vector<int> ways(n+1);
        ways[0]=1;
        ways[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]!='0')
            {//(1)满足一步的情况
                //若s[i-1]不为0,则s[i-1]可单独存在,s[i]可由s[i-1]走1步到达
                ways[i] = ways[i-1];
            }
            //(2)满足两步的情况
            //承接上面，若s[i-2]*10+s[i-1]<=26,则s[i]可由s[i-2]走2步到达
            //if(0<stoi(s.substr(i-2,2))<=26) //错误！！！
            if(s[i-2]=='1' || (s[i-2]=='2'&&s[i-1]<='6'))
            {
                ways[i] += ways[i-2];//因与前面是先后顺序,所以是+=
            }
        }
        return ways[n];
    }
};


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}