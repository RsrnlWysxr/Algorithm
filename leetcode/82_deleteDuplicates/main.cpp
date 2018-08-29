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
    // 传入当前节点，以及下个节点的值
    // 返回已经删除了该值的链表的头节点
    ListNode* deleteDuplicates( ListNode* cur,int val )
    {
        if( cur == NULL || cur->val != val )
            return cur;
        else //cur->val == val
        {
            auto delNode = cur;
            cur = delNode->next;
            delete delNode;
            return  deleteDuplicates( cur,val );
        }
    }
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if( head == NULL || head->next == NULL )
            return head;

        auto dummyHead = new ListNode( -1 );
        dummyHead->next = head;

        auto cur = dummyHead;
        while( cur->next != NULL && cur->next->next != NULL )
        {
            if( cur->next->val == cur->next->next->val )
                cur->next = deleteDuplicates( cur->next, cur->next->val );
            else
                cur = cur->next;
        }
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


int main() {
    int nums[] = { 1, 1, 1, 2, 3 };
    auto head = creatListNode( nums, sizeof(nums) / sizeof( int ));
    printListNode( Solution().deleteDuplicates( head ) );
    return 0;
}