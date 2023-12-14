//
//  main.cpp
//  DS图应用--最短路径
//
//  Created by Shockley on 11/22/23.
//

#include <iostream>
#include <vector>
using namespace std;
void dijkstra(vector<vector<int>> &g,int src,vector<int> &dist,vector<int>&pre)
{
    int n=g.size();
    vector<bool> visited(n,false);
    dist[src]=0;
    for(int i=0;i<n;i++)
    {
        int u=-1;
        for(int j=0;j<n;j++)
        {
            if(!visited[j]&&(u==-1||dist[j]<dist[u]))
            {
                u=j;
            }
        }
        if(dist[u]==9999)
            break;
        visited[u]=true;
        //更新dist
        for(int v=0;v<n;v++)
        {
            if(!visited[v]&&g[u][v]!=0&&dist[u]+g[u][v]<dist[v])
            {
                dist[v]=dist[u]+g[u][v];
                pre[v]=u;
            }
        }

    }
}
void printPath(int v,vector<int>&pre)
{
    if(pre[v]!=-1)
    {
        printPath(pre[v],pre);
        cout<<" ";
    }
    cout<<v;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> graph(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>graph[i][j];
            }
        }
        int v0;
        cin>>v0;
        vector<int> dist(n,9999);//存储最短路径
        vector<int> prev(n,-1);//前驱节点,为了回溯路径
        dijkstra(graph,v0,dist,prev);
        for(int i=0;i<n;i++)
        {
            if(i!=v0)
            {
                cout << v0 << "-" << i << "-" << dist[i] << "----[";
                printPath(i,prev);
                cout<<" ]"<<endl;
            }
        }
    }
    
    return 0;
}
