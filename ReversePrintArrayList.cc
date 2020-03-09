/*
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
/*
//段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起
//--->当链表非常长的时候，会导致函数的调用层级很深，会导致函数的调用栈溢出
        if(head != nullptr)
        {
            if(head->next != nullptr)
            {
                printListFromTailToHead(head->next);
            }
            v.push_back(head->val);
        }
*/
        if(head != nullptr)
        {
            stack<int> s;
            vector<int> v;
            while(head)
            {
                s.push(head->val);
                head = head->next;
            }
            while(!s.empty())
            {
                v.push_back(s.top());
                s.pop();
            }
            return v;
        }
    }
};