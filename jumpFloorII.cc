/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
class Solution {
public:
    int jumpFloorII(int number) {
#if 0
        //青蛙每上一阶台阶的总共方法是跳上前n阶方法总和
        int& n = number;
        vector<int> v(n + 2, 0);
        v[1] = 1;
        v[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            int sum = 1;
            for(int j = 1; j < i; j++)
            {
                sum += v[j];
            }
            v[i] = sum;
        }
        return v[n];
#endif
        // 2 ^ (n - 1)  数学归纳法
        if(number <= 1)
        {
            return number;
        }
        else
        {
            return 1 << (number - 1);
        }
    }
};
