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
// 传入待翻转节点的第一个节点，以及要翻转的个数
// 返回翻转后节点的第一个节点

private:
    ListNode* reverseKGroupR( ListNode* node, int k )
    {
        auto dummyHead = new ListNode( 0 );
        dummyHead->next = node;
        auto tmpNode = node;
        int k_count = 0;

        while( tmpNode != nullptr && k_count != k )
        {
            ++k_count;
            tmpNode = tmpNode->next;
        }
        if( k_count != k )
            return node;

        // 找到了k个节点
        // 翻转操作
        auto pre = reverseKGroupR( tmpNode, k );
        auto cur = node;
        while( k_count > 0 )
        {
            auto tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
            --k_count;
        }
        return pre;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        auto dummyHead = new ListNode( 0 );
        dummyHead->next = reverseKGroupR( head, k );
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
    int nums[] = { 1, 2, 3, 4, 5 };
    auto head = creatListNode( nums , 5 );
    printListNode( Solution().reverseKGroup( head, 2 ) );
    return 0;
}