#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        //判断无输入
        int number = 0;//标记计数
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != nums[number])
            {
                number++;
                nums[number] = nums[i];
            }
        }
        number+=1; //标记+1即为数字个数
        return number;
    }
};

int main()
{
    vector<int> nums{1,1,2,3,3,5,6,7,7,7};
    Solution a;
    int n = a.removeDuplicates(nums);
    cout << n << endl;
    for(int i = 0; i < n; i++)
        cout << nums[i] << " ";
    return 0;
}