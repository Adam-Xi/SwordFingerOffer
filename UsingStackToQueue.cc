/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型
*/
#include <stack>

class Solution
{
    //另一个栈始终进行压栈操作，另一个栈始终进行出栈操作
    //压栈时：直接压栈
    //出栈时：若出栈的栈为空，将压栈的栈中所有内容依次出压栈的栈，并进出栈的栈，并出栈
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
            if(!stack1.empty())
            {
                while(!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
        }
        int top = stack2.top();
        stack2.pop();
        return top;
    }

private:
    std::stack<int> stack1;  //压栈的栈
    std::stack<int> stack2;  //出栈的栈
};
