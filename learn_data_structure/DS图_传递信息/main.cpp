//
//  main.cpp
//  DS图_传递信息
//
//  Created by Shockley on 11/22/23.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int dp[10][10];//用于存储动态规划的状态。dp[i][j] 表示经过 i 轮传递后，信息到达玩家 j 的方案数

int wayNum(int n,vector<vector<int>> &relation,int k)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<k;i++)//k次传递
    {
        for(int j=0;j<n;j++)//j是终点
        {
            if(dp[i][j]>0)//从i到j有路径
            {
                for(int v:relation[j])
                {
                    dp[i+1][v]+=dp[i][j];
                }
            }
        }
    }
    return dp[k][n-1];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        int k;
        int len;
        cin>>n>>len;
        vector<vector<int>> G(10);
        for(int i=0;i<len;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
        }
        cin>>k;
        cout<<wayNum(n,G,k)<<endl;
    }
    
    return 0;
}
