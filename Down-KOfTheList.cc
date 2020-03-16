/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr || k == 0)
        {
            return nullptr;
        }
        ListNode* first = pListHead;
        for(unsigned int i = 0; i < k - 1; i++)
        {
            if(first->next)
            {
                first = first->next;
            }
            else
            {
                return nullptr;
            }
        }
        ListNode* last = pListHead;
        
        while(first->next)
        {
            first = first->next;
            last = last->next;
        }
        return last;
    }
};