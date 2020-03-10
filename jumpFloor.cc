/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

class Solution {
public:
    int jumpFloor(int number) {
        int index1 = 1;
        int index2 = 2;
        int index3;
        if(number == 1)
        {
            return index1;
        }
        if(number == 2)
        {
            return index2;
        }
        for(int i  = 3; i <= number; i++)
        {
            index3 = index1 + index2;
            index1 = index2;
            index2 = index3;
        }
        return index3;
    }
};