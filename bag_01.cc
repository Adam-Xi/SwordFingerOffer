/*
 * 0-1背包问题
 * 在使用动态规划算法求解0-1背包问题时，使用二维数组m[i][j]存储背包剩余容量为j，可选物品为i、i+1、……、n时0-1背包问题的最优值
 * 绘制:
 *   价值数组v = {8, 10, 6, 3, 7, 2}，
 *   重量数组w = {4, 6, 2, 2, 5, 1}，
 *   背包容量C = 12时对应的m[i][j]数组
 */

#include <iostream>
#include <cstring>
using namespace std;

const int N = 20;
 
int v[N] = {0, 8, 10, 6, 3, 7, 2};
int w[N] = {0, 4, 6, 2, 2, 5, 1};
int x[N];
int m[N][N];
int c = 12;
int n = 6;

void traceback()
{
    for(int i=n;i>1;i--)
    {
        if(m[i][c]==m[i-1][c])
            x[i]=0;
        else
        {
            x[i]=1;
            c-=w[i];
        }
                
    }
    x[1]=(m[1][c]>0)?1:0;
}


// m[i][j] 表示在面对第i件物品，且背包剩余容量为j时所能获得的最大价值
// if(j >= w[i])
//     m[i][j] = max(m[i-1][j], m[i-1][j-w[i]] + v[i]);  // 背包可以放入当前物品，但需要判断是否价值最大化
// else
//     m[i][j] = m[i-1][j];  // 背包容量不够
int main()
{
    memset(m,0,sizeof(m));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(j>=w[i])
                m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);
            else
                m[i][j]=m[i-1][j];
        }
            
    }
    
    cout << "动态规划搜索表为：" << endl;
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=c;j++)
        {
            printf("%-4d ", m[i][j]);
        }
        cout << endl;
                    
    }
    
    traceback();
    cout << "所选择的最优方案：" << endl;
    for(int i=1;i<=n;i++)
        printf("%-4d ", x[i]);
    cout << endl;

    return 0;
}
