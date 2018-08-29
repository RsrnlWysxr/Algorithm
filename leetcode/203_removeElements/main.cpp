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
    ListNode* removeElements(ListNode* head, int val)
    {
        auto dummyHead = new ListNode( -1 );    // 虚拟头节点
        dummyHead->next = head;

        auto cur = dummyHead;
        while ( cur->next != NULL )
        {
            if( cur->next->val == val )
            {
                auto delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }
            else
                cur = cur->next;
        }
        return dummyHead->next;
    }
};


int main()
{
    auto head = new ListNode(1);
    int nums[] = { 2, 6, 3, 4, 5, 6 };
    auto cur = head;
    for( auto x : nums )
    {
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    cur->next = NULL;

    cur = Solution().removeElements( head, 6 );
    while( cur != NULL )
    {
        cout << cur->val << " -> ";
        cur = cur->next;
    }
    cout << "NULL" << endl;



    return 0;
}