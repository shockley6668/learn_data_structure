//
//  main.cpp
//  追星
//
//  Created by Shockley on 11/22/23.
//

#include <iostream>
#include "vector"
using namespace std;
void dijkstra(vector<vector<int>>& g,int src,vector<int> &dist,vector<int> &pre)
{
    int n=g.size();
    vector<bool> visited(n,false);
    dist[src]=0;
    
    for(int i=0;i<n;i++)
    {
        int current=-1;//记录当前搜索节点
        for(int j=0;j<n;j++)
        {
            //寻找下一个为访问的并且是最小的节点，第一个节点要进行特殊判断
            if(visited[j]==false&&(current==-1||dist[current]>dist[j]))
            {
                current=j;
            }
        }
        //如果连第一个节点都没露可走
        if(dist[current]==9999)
        {
            break;
        }
        //把写一个选择的节点标注为已经访问
        visited[current]=true;
        //更新src到各个节点的最短路径
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false&&g[current][i]!=0&&(g[current][i]+dist[current])<dist[i])
            {
                dist[i]=g[current][i]+dist[current];
                pre[i]=current;
            }
                
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n,vector<int>(n,9999));
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        --u; --v;
        if(graph[u][v]>w)
            graph[u][v] = graph[v][u] = w;
    }
    vector<int> dist(n,9999);//用于记录从src到各个节点的最短距离
    vector<int> pre(n); //用于记录该节点的前驱节点是谁，用于回退，相当于表格中的*
    dijkstra(graph,0,dist,pre);
    cout<<dist[n-1]<<endl;
    return 0;
}
