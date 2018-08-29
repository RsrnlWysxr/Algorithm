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
    ListNode* partition(ListNode* head, int x)
    {

        ListNode* lDummyHead = new ListNode( -1 );  // 小于部分的虚拟头节点
        ListNode* gDummyHead = new ListNode( -1 );  // 等于部分的虚拟头节点

        ListNode* lPre = lDummyHead;    // 小于部分cur前一个节点
        ListNode* gPre = gDummyHead;    // 大于等于部分cur前一个节点
        ListNode* cur = head;       // 当前考察节点

        while( cur != NULL )
        {
            if( cur->val < x )  // 穿起小于部分
            {
                lPre->next = cur;
                cur = cur->next;
                lPre = lPre->next;
                lPre->next = NULL;
            }
            else    // 穿起大于等于部分
            {
                gPre->next = cur;
                cur = cur->next;
                gPre = gPre->next;
                gPre->next = NULL;
            }
        }
        // 连接两个部分
        lPre->next = gDummyHead->next;
        head = lDummyHead->next;

        delete lDummyHead;
        delete gDummyHead;

        return head;
    }
};







int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}