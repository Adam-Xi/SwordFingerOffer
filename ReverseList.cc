/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。
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
    ListNode* ReverseList(ListNode* pHead) {
        if(nullptr == pHead || nullptr == pHead->next)
        {
            return pHead;
        }
        ListNode* pPrev = nullptr;
        ListNode* pNext = nullptr;
        while(pHead)
        {
            pNext = pHead->next;
            pHead->next = pPrev;
            pPrev = pHead;
            pHead = pNext;
        }
        return pPrev;
    }
};