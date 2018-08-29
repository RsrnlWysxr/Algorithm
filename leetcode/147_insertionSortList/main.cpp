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
    ListNode* insertionSortList(ListNode* head)
    {

        auto dummyHead = new ListNode(-1);
        dummyHead->next = head;
        auto cur1= dummyHead->next;
        while( cur1 && cur1->next )
        {
            auto cur2 = cur1->next;
            if( cur2->val >= cur1->val )
            {
                cur1 = cur1->next;
                continue;
            }
            // 删除当前节点
            auto curNode = cur2;
            cur1->next = cur2->next;
            auto pre = dummyHead;
            // 寻找插入位置
            while( pre != cur1->next && pre->next && pre->next->val <= curNode->val)  // 循环终止位置为cur1
            {
//                if( pre->next->val <= curNode->val )
                    pre = pre->next;
//                else    // recur->next->val > delNode
//                    break;
            }   // 循环结束pre指向待插入位置的前一个节点
//            if( pre == cur1 )
//                cur1 = cur1->next;
            curNode->next = pre->next;
            pre->next = curNode;

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






int main()
{
    int nums[] = { -1, 5, 3, 4, 0 };
    auto head = creatListNode( nums, 5 );
    auto prthead = Solution().insertionSortList( head );
    printListNode( prthead );
    return 0;
}