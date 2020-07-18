/* ========================================================
 #   Copyright (C)2020 All rights reserved.
 # 
 #   Author        : Adam-Xi
 #   Filename      : BitwiseAND.cc
 #   Last modified : 2020-07-18 13:32
 #   Description   : 给定范围[m, n]，其中0<=m<=n<=2147483647,返回该范围内所有数字的按位与
 #                     (包含m,n两个端点)
 # 
 # ======================================================== */

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        /*
         *            5 - 7
         *      1001 & 1010 & 1011
         *        1000   &   1011
         *             1000
         *            11 - 14
         *      1011 & 1100 & 1101 & 1110
         *        1000   &    1101 & 1110
         *          1000    &      1110
         *                   1000
         * */
        int offset = 0;
        while(m != n)
        {
            m >>= 1;
            n >>= 1;
            offset++;

        }
        return n << offset;

    }

};
