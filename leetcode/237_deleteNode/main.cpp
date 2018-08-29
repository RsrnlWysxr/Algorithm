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
    void deleteNode(ListNode* node)
    {
        node->val = node->next->val;
        auto delNode = node->next;
        node->next = delNode->next;
        delete delNode;
    }
};


int main()
{

}