#include <iostream>



struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        auto dummyhead = new ListNode( 0 );
        dummyhead->next = head;

        auto p = dummyhead;
        auto q = dummyhead;

        for( int i = 0; i < n + 1; ++i )
            q = q ->next;

        while( q )
        {
            p = p->next;
            q = q->next;
        }
        // 循环结束， p指向待删除节点的前一个节点，q指向NULL
        auto delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        return dummyhead->next;
    }
};












int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}