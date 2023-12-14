//
//  main.cpp
//  DS最小生成树
//
//  Created by Shockley on 11/15/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#define INT_MAX 99999
using namespace std;
struct Edge
{
    int u,v,w;
    bool operator<(const Edge& rhs) const{
        return w<rhs.w;
    }
};
class Graph
{
public:
    int n;
    vector<vector<pair<int, int>>> adj; // 邻接表
    vector<Edge> edges;
    Graph(int n):n(n),adj(n){}
    void addEdge(int u,int v,int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({u,v,w});
    }


    /*8*Prim算法的主要步骤包括：

1、初始化一个空的最小生成树集合。
2、选择一个初始节点，将其添加到最小生成树集合中。
3、在所有连接最小生成树集合和其余节点的边中，选择权重最小的边，将其对应的节点添加到最小生成树集合中。
4、重复步骤3，直到所有节点都被添加到最小生成树集合中。***/
    pair<int, vector<Edge>> prim(int start) {
    vector<bool> inMST(n, false); // 标记顶点是否在最小生成树中
    vector<int> dist(n, INT_MAX); // 记录顶点到生成树的最短距离
    vector<int> parent(n, -1); // 记录顶点的父节点
    vector<Edge> mstEdges; // 用于存储最小生成树的边
    int totalWeight = 0; // 记录最小生成树的总权重

    dist[start] = 0;

    for (int count = 0; count < n ; count++) {
        int u = -1;
        for(int i = 0; i < n; i++) {
            if (!inMST[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        inMST[u] = true;
        totalWeight += dist[u];

        if (parent[u] != -1) {
            mstEdges.push_back({parent[u], u, dist[u]});
        }
        // 更新与u相邻的顶点的距离
        for (auto& edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if (!inMST[v] && w < dist[v]) {
                dist[v] = w;
                parent[v] = u;
            }
        }
    }

    return {totalWeight, mstEdges};
}
    pair<int,vector<Edge>> Kruskal(){
        sort(edges.begin(),edges.end());
        vector<int> parent(n); //并查集的父节点数组
        for(int i=0;i<n;i++)
        {
            parent[i]=i; // 初始化并查集，每个节点的父节点都是自己
        }
        function<int(int)> find=[&](int x){
            if(x!=parent[x]) //如果x不是根节点
            {
                parent[x]=find(parent[x]); // 路径压缩,递归调用find将x的父节点设为根节点,
            }
            return parent[x];
        };
        int totalWeight=0;
        vector<Edge> mstEdges;
        for(auto &edge:edges)
        {
            int u=find(edge.u);//找到u的根节点
            int v=find(edge.v);//找到v的根节点
            int w=edge.w;
            if(u!=v)//如果u,v不在同一个并查集中
            {
                parent[u]=v; // 将u的根节点设为v的根节点，因为v早就有一个根节点了
                totalWeight+=w;
                if (edge.u > edge.v) {
                swap(edge.u, edge.v);
                }
                mstEdges.push_back(edge);
            }
           
        }
        return {totalWeight,mstEdges};
    }

};
int main()
{
    int n;
    cin>>n;
    Graph g(n);
    unordered_map<string,int> indexmap;
    vector<string> vertexs(n);
    for(int i=0;i<n;i++)
    {
        string vertex;
        cin>>vertex;
        vertexs[i]=vertex;
        indexmap[vertex]=i;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        string u,v;
        int w;
        cin>>u>>v>>w;
        g.addEdge(indexmap[u],indexmap[v],w);
    }
    string start_vertex;
    cin>>start_vertex;
    pair<int,vector<Edge>> result=g.prim(indexmap[start_vertex]);
    cout<<result.first<<endl;
    cout<<"prim:"<<endl;
    for(auto& e:result.second)
    {
        cout<<vertexs[e.u]<<" "<<vertexs[e.v]<<" "<<e.w<<endl;
    }
    result=g.Kruskal();
    cout<<"kruskal:"<<endl;
    for(auto& e:result.second)
    {
        cout<<vertexs[e.u]<<" "<<vertexs[e.v]<<" "<<e.w<<endl;
    }
    return 0;
}

