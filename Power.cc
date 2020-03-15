/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。
求base的exponent次方。
保证base和exponent不同时为0
*/

class Solution {
public:
    double Power(double base, int exponent) {
        //return pow(base, exponent);
        long long p = abs((long long)exponent);
        double res = 1.0;
        while(p)
        {
            if(p & 1)
            {
                //在指数循环右移的过程中，始终都会存在奇数次幂，执行当前步骤
                res *= base;  //当指数不为0时，将结果保存在res中
            }
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1 / res : res;
    }
};

