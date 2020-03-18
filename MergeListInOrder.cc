/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(nullptr == pHead1)
        {
            return pHead2;
        }
        if(nullptr == pHead2)
        {
            return pHead1;
        }
        
        ListNode* pHead = new ListNode(-1);
        ListNode* curNode = pHead;
        while(pHead1 && pHead2)
        {
            if(pHead1->val < pHead2->val)
            {
                curNode->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                curNode->next = pHead2;
                pHead2 = pHead2->next;
            }
            curNode = curNode->next;
        }
        if(pHead1)
        {
            curNode->next = pHead1;
        }
        else if(pHead2)
        {
            curNode->next = pHead2;
        }
        return pHead->next;
    }
};