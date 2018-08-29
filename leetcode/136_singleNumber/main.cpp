#include <iostream>
#include <vector>
using namespace std;
// 异或运算  满足   交换律
// 相同的数异或为0
// 任何数和0异或都是这个数字本身
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int result = 0;
        for( int i = 0; i < nums.size(); ++i)
        {
            result ^= nums[i];
        }
        return result;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}