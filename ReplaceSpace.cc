/*
 * author：Adam-Xi
 * date：2020-03-09
 * description：
 *  请实现一个函数，将一个字符串中的每个空格替换成“%20”
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */
#include <iostream>
using namespace std;

class Solution 
{
public:
	void replaceSpace(char *str,int length) 
    {
        if(str == nullptr)
        {
            return ;
        }
        int originLength = 0;
        int numOfBlank = 0;
        int i = 0;
        while(str[i] != '\0')
        {
            ++originLength;
            if(str[i] == ' ')
            {
                ++numOfBlank;
            }
            ++i;
        }
        int newLength = originLength + numOfBlank * 2;
        if(newLength > length)
        {
            return ;
        }
        int indexOfOrigin = originLength;
        int indexOfNew = newLength;
        while(indexOfOrigin >= 0 && indexOfNew > indexOfOrigin)
        {
            if(str[indexOfOrigin] == ' ')
            {
                str[indexOfNew--] = '0';
                str[indexOfNew--] = '2';
                str[indexOfNew--] = '%';
            }
            else
            {
                str[indexOfNew--] = str[indexOfOrigin];
            }
            --indexOfOrigin;

        }
	}
};