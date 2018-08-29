#include <iostream>
#include <vector>
#include <vector>
#include <queue>

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
    class CompareListNode
    {
    public:
        bool operator()( ListNode* l1, ListNode* l2 )
        {
            return l1->val > l2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if( lists.empty() )
            return NULL;

        auto dummyHead = new ListNode( 0 );
        priority_queue< ListNode*, vector<ListNode*>, CompareListNode > pq;

        for( auto x: lists )
            if( x )
                pq.push(x);

        auto cur = dummyHead;

        while( !pq.empty() )
        {
            auto nextNode = pq.top();
            pq.pop();

            if( nextNode->next != NULL )
                pq.push( nextNode->next );

            cur->next = nextNode;
            nextNode->next = NULL;
            cur = cur->next;
        }
        return dummyHead->next;
    }
};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}