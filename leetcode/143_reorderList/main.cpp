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

    // 传入链表头节点，返还中间节点的前一个
    ListNode* getMiddle( ListNode* head )
    {
        auto slow = head;
        auto fast = head;
        while( fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 传入链表的头节点以及一个结束节点，翻转链表后，链表结尾指向结束节点，返回翻转后的头节点
    ListNode* reverseList( ListNode* head, ListNode* end )
    {
        auto pre = end;
        auto cur = head;
        while( cur )
        {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

public:
    void reorderList(ListNode* head)
    {
        if( !head )
            return;

        auto dummyHead = new ListNode( 0 );
        dummyHead->next = head;

        auto mid = getMiddle( head );

        // 翻转后面的节点
        auto dummyHead2 = new ListNode( 0 );
        dummyHead2->next = reverseList( mid->next, NULL );
        mid->next = NULL;

        // 依次插入
        auto cur = dummyHead;   // 插入节点的前一个节点
        auto incur = dummyHead2->next;  // 插入的节点
        bool count = false;     // 为true插入
        while( cur  && incur )
        {
            if( count )
            {
                auto nextincur = incur->next;
                auto next = cur->next;
                cur->next = incur;
                incur->next = next;
                incur = nextincur;
            }
            cur = cur->next;
            count = !count;
        }
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
    int nums[] = { 1, 2, 3, 4 };
    auto head = creatListNode( nums, 4 );
    Solution().reorderList( head );
    printListNode( head );
    return 0;
}