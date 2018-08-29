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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        auto dummyHead = new ListNode( -1 );
        auto cur = dummyHead;   // 返回链表中当前考察的位置
        auto lcur = l1;         // 指在l1的指针
        auto rcur = l2;         // 指在l2的指针

        while( lcur != NULL || rcur != NULL )
        {
            int n = 0;
            if( lcur == NULL )
            {
                n = rcur->val;
                rcur = rcur->next;
            }
            else if( rcur == NULL )
            {
                n = lcur->val;
                lcur = lcur->next;
            }
            else if( lcur->val < rcur->val )
            {
                n = lcur->val;
                lcur = lcur->next;
            }
            else // rcur->val <= lcur->val
            {
                n = rcur->val;
                rcur = rcur->next;
            }
            cur->next = new ListNode( n );
            cur = cur->next;
        }
        return dummyHead->next;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}