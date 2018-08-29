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
    ListNode* swapPairs(ListNode* head)
    {
        auto dummyHead = new  ListNode( -1 );
        dummyHead->next = head;
        auto pre = dummyHead;

        while( pre && pre->next && pre->next ->next )
        {
            auto node1 = pre->next;
            auto node2 = node1->next;
            auto next = node2->next;

            // 交换
            node2->next = node1;
            node1->next = next;
            pre->next = node2;

            pre = node1;
        }

        return dummyHead->next;
    }
};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}