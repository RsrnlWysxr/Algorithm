#include <iostream>

using namespace std;

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
//        // 创建虚拟头节点
//        ListNode* dummyHead = new ListNode(0);
//        dummyHead->next = head;
        if( head == NULL )
            return head;
        ListNode* pre = head;       // 前一个节点的指针，用作比值
        ListNode* cur = head->next;     // 当前考察节点

        // 循环从第二个开始
        while( cur != NULL )
        {
            if( pre->val == cur->val )
            {
                ListNode* delNode = cur;
                pre->next = cur->next;
                cur = cur->next;
                delete delNode;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};










int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}