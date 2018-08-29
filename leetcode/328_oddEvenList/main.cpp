#include <iostream>

using namespace std;



struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if( head == NULL || head->next == NULL )
            return head;

        int count = 0;
        ListNode* douStar = head->next;   // 记录偶节点开始位置
        ListNode* oddEnd = NULL;        // 记录奇节点结束位置

        ListNode* cur = head;   // 当前考察节点
        // 找到奇数节点结束位置
        while( cur->next != NULL )
        {
            ++count;
            ListNode* next = cur->next;     // 记录下一个节点
            if( count % 2 == 0 && cur->next->next == NULL )
                oddEnd = cur->next;
            else if( count % 2 == 1 && cur->next->next ==NULL )
                oddEnd = cur;
            cur->next = cur->next->next;
            cur = next;
        }
        if( count % 2 == 0 )
            cur->next = NULL;

        // 连接
        oddEnd->next = douStar;
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}