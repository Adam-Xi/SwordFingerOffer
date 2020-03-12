/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
        {
            return 0;
        }
        vector<int>& v = rotateArray;
        int start = 0;
        int end = v.size() - 1;
        int mid = 0;
        while(v[start] >= v[end])
        {
            if(end - start == 1)
            {
                mid = end;
                break;
            }
            int mid = (start + end) / 2;
            if(v[start] == v[mid] && v[mid] == v[end])
            {
                return MinInOrder(v, start, end);
            }
            
            if(v[mid] >= v[start])
            {
                start = mid;
            }
            else if(v[mid] <= v[end])
            {
                end = mid;
            }
        }
        return v[mid];
    }
    int MinInOrder(vector<int>& v, int start, int end)
    {
        int res = v[start];
        for(int i = start + 1; i <= end; i++)
        {
            if(res > v[i])
            {
                res = v[i];
            }
        }
        return res;
    }
};