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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        // 计数一致，设置虚拟头节点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        for( int i = 0; i < m - 1; ++i )
            pre = pre->next;
            // 循环结束，pre指向了待反转链表入界的前一个位置

        ListNode* memoPre = pre;

        ListNode* end = dummyHead;
        for( int i = 0; i < n + 1; ++i )
            end = end->next;
            // 循环结束，end指向了待反转链表出界的第一个位置

        ListNode* cur = pre->next;
        ListNode* next = NULL;
        while( cur != end )
        {
            next = cur->next;
            cur->next = pre;    // 反转
            pre = cur;
            cur = next;
        }

        memoPre->next->next = next;
        memoPre->next = pre;

        return dummyHead->next;
    }
};





int main()
{
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for( int i = 2; i < 6; ++i )
    {
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    ListNode* prt = Solution().reverseBetween( head, 2, 4 );

    // 打印
//    ListNode* prt = head;
    while()
    {
        cout << prt->val << "->";
        prt = prt->next;
    }
    cout << "NULL" << endl;
    return 0;
}