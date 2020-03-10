/*
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Solution {
public:
    int rectCover(int number) {
        // 1 --- 1
        // 2 --- 2
        // 3 --- 3
        // 4 --- 5
        int& n = number;
        if(n == 0 || n == 1 || n == 2)
        {
            return n;
        }
        int index1 = 1;
        int index2 = 2;
        int index3;
        for(int i = 3; i <= n; i++)
        {
            index3 = index1 + index2;
            index1 = index2;
            index2 = index3;
        }
        return index3;
    }
};