/*
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

class Solution {
public:
     int  NumberOf1(int n) {
#if 0
         int count = 0;
         unsigned int flag = 1;
         while(flag)
         {
             if(n & flag)
             {
                 count++;
             }
             flag <<= 1;
         }
         return count;
#endif
         int count = 0;
         while(n)
         {
             n = (n - 1) & n;
             count++;
         }
         return count;
     }
};