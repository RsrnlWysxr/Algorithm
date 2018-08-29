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
    ListNode* getMiddle( ListNode* head )
    {
        auto dummyHead = new ListNode( 0 );
        dummyHead->next = head;
        auto slow = dummyHead;
        auto fast = dummyHead;
        while( fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList( ListNode* node, ListNode* end )
    {
        auto pre = end;
        auto cur = node;
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
    bool isPalindrome(ListNode* head)
    {
        if( !head || !head->next )
            return  true;

        auto dummyHead = new ListNode( 0 );
        dummyHead->next = head;

        auto mid = getMiddle( head );
        mid->next = reverseList( mid->next, NULL );

        auto l = dummyHead->next;
        auto r = mid->next;
        while( r )
        {
            if( l->val != r->val )
                return false;
            l = l->next;
            r = r->next;
        }
        return true;
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
    int nums[] = { 1, 0, 1 };
    auto head = creatListNode( nums, 3 );
    Solution().isPalindrome( head );
    return 0;
}