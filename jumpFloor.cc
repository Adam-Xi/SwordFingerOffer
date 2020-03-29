/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

#include <vector>

class Solution {
public:
#if 0
// 递推法
    int jumpFloor(int number) 
    {
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
#endif
// 动态规划法
    int Func(std::vector<int>& dp, int n) 
    {
        if(n == 1 || n == 2)
        {
            return n;
        }
        if(!dp[n - 1])  // 判断 n-1 的状态是否被计算过
        {
            dp[n - 1] = Func(dp, n - 1);
        }
        if(!dp[n - 2])  // 判断 n-2 的状态是否被计算过
        {
            dp[n - 2] = Func(dp, n - 2);
        }
        return dp[n - 1] + dp[n - 2];
    }

    int jumpFloor(int number) 
    {
        std::vector<int> dp(number, 0);
        return Func(dp, number);
    }
};
