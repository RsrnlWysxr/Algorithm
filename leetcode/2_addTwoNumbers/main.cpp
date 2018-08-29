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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto resDummyHead = new ListNode(-1);      // 返回链表的虚拟头节点
        auto cur = resDummyHead;         // 当天输出链表待填入值
        int carry = 0;      // 进位
        while( l1 != NULL || l2 != NULL )
        {
            int x = ( l1 != NULL ) ? l1->val : 0;
            int y = ( l2 != NULL ) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            cur->next = new ListNode( sum % 10 );
            cur = cur->next;
            if( l1 != NULL )
                l1 = l1->next;
            if( l2 != NULL )
                l2 = l2->next;
        }
        if( carry > 0 )
            cur->next = new ListNode( carry );
        return resDummyHead->next;
    }
};






int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}