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
private:
    // 传入一个链表的头节点与结束节点，返回翻转后的头节点
    ListNode* reverseList( ListNode* node, ListNode* end )
    {
        auto pre = end;
        auto cur = node;
        while( cur != end )
        {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if( head == NULL )
            return head;

        // 先翻转后面，再翻转前面，最后一起翻转
        auto dummyHead = new ListNode( 0 );
        dummyHead->next = head;

        // 防止k大于链表长度，故计算链表长度
        int count = 0;
        auto cur = head;
        while( cur )
        {
            count++;
            cur = cur->next;
        }

        k = ( k + count ) % count;

        auto p = dummyHead;
        auto q = dummyHead;

        for( int i = 0; i < k + 1; ++i )
            q = q->next;
        while( q )
        {
            p = p->next;
            q = q->next;
        }
        p->next = reverseList( p->next, q );
        dummyHead->next = reverseList( dummyHead->next, p->next );
        dummyHead->next = reverseList( dummyHead->next, NULL );
        return dummyHead->next;
    }
};


ListNode* creatListNode( int nums[], int n )
{
    auto dummyHead = new ListNode( -1 );
    auto cur = dummyHead;
    for( int i = 0; i < n; ++i )
    {
        cur->next = new ListNode( nums[i] );
        cur = cur->next;
    }
    cur->next = NULL;
    return dummyHead->next;
}


void printListNode( ListNode* head )
{
    ListNode* prthead = head;
    while( prthead != NULL )
    {
        cout << prthead->val << "->";
        prthead = prthead->next;
    }
    cout << "NULL" << endl;
}



int main()
{
    int nums[] = { 1, 2, 3, 4, 5 };
    int k = 2;
    auto head = creatListNode( nums, 5 );
    auto prt = Solution().rotateRight( head, k );
    printListNode( prt );
    return 0;
}