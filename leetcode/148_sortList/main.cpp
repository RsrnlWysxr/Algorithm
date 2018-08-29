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
    // 传入链表头节点，返回该链表的中间节点
    ListNode* getMiddle( ListNode* head )
    {
        auto slow = head;
        auto fast = head;
        while( fast->next && fast->next->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    // 合并两个有序链表
    // 传入两个链表头节点，返回合并排好序链表的头节点
    ListNode* merge( ListNode* l1, ListNode* l2 )
    {
        auto dummyHead = new ListNode( 0 );
        auto cur = dummyHead;
        auto lcur = l1;
        auto rcur = l2;
        while( lcur || rcur )
        {
            int n = 0;
            if( !lcur )
            {
                n = rcur->val;
                rcur = rcur->next;
            }
            else if( !rcur )
            {
                n = lcur->val;
                lcur = lcur->next;
            }
            else if( lcur->val < rcur->val )
            {
                n = lcur->val;
                lcur = lcur->next;
            }
            else
            {
                n = rcur->val;
                rcur = rcur->next;
            }
            cur->next = new ListNode(n);
            cur = cur->next;
        }
        return dummyHead->next;
    }
    // 归并排序递归算法
    // 传入链表，将链表分为两部分，分别排序后再融合
    // 返回排好序的链表头节点
    ListNode* sort( ListNode* node )
    {
        if( node == NULL || node->next == NULL )
            return node;
        auto mid = getMiddle( node );
        auto next = mid->next;
        mid->next = NULL;
        return merge( sort( node ), sort( next ) );
    }

public:
    ListNode* sortList(ListNode* head)
    {
        return sort( head );
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




int main() {
    int nums[] = { 4, 2, 1, 3 };
    auto head = creatListNode( nums, 4 );
    auto prt = Solution().sortList( head );
    printListNode( prt );
    return 0;
}