#include <iostream>
#include <stack>

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
    ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 )
    {
        auto resDummyHead = new ListNode( -1 );         // 返回链表的虚拟头节点

        stack<int> s_1;        // 保存链表l1的栈
        stack<int> s_2;        // 保存链表l2的栈
        while( l1 != NULL || l2 != NULL )
        {
            if( l1 != NULL ) s_1.push( l1->val );
            if( l2 != NULL ) s_2.push( l2->val );
            if( l1 != NULL )  l1 = l1->next;
            if( l2 != NULL )  l2 = l2->next;
        }

        stack<int> s_r;     // 返回链表的栈
        int x = 0;      // 链表1的值
        int y = 0;      // 链表2的值
        int carry = 0;  // 进位
        int sum = 0;    // 每次的和
        int r = 0;      // 当前返回链表节点的值
        while( !s_1.empty() || !s_2.empty() )
        {
            if( !s_1.empty() )
            {
                x = s_1.top();
                s_1.pop();
            }
            else
                x = 0;
            if( !s_2.empty() )
            {
                y = s_2.top();
                s_2.pop();
            }
            else y = 0;
            sum = x + y + carry;
            r = sum % 10;
            carry = sum / 10;
            s_r.push( r );
        }
        if( carry == 1 )
            s_r.push( 1 );

        ListNode* cur = resDummyHead;
        while( !s_r.empty() )
        {
            cur->next = new ListNode( s_r.top() );
            s_r.pop();
            cur = cur->next;
        }
        cur->next = NULL;
        return resDummyHead->next;
    }
};








int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}