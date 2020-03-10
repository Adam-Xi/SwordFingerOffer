/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）
n<=39
*/

class Solution {
public:
    int Fibonacci(int n) {
        int index1 = 0;
        int index2 = 1;
        int index3;
        if(n == 0)
        {
            return index1;
        }
        if(n == 1)
        {
            return index2;
        }
        for(int i = 2; i <= n; i++)
        {
            index3 = index1 + index2;
            index1 = index2;
            index2 = index3;
        }
        return index3;
        
    }
};