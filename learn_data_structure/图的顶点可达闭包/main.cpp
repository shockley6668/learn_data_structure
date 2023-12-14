//
//  main.cpp
//  图的顶点可达闭包
//
//  Created by Shockley on 11/22/23.
//

#include <iostream>
#include "vector"
#include "stack"
#include "queue"
using namespace std;
// void dfs(vector<vector<int>>& g,int u,int ou,vector<bool>& visited)
// {
//     stack<int> s;
//     s.push(u);
//     while (!s.empty())
//     {
//         int u=s.top();
//         s.pop();
//         if(!visited[u])
//         {
//             if(u!=ou)
//                 visited[u]=true;
//             for(int i=0;i<g.size();i++)
//             {
//                 if(g[u][i]==1&&!visited[i])
//                     s.push(i);
//             }
//         }
//     }
    
// }
// void computeReacheable(vector<vector<int>> &g)
// {
//     int n=g.size();
//     for(int i=0;i<n;i++)
//     {
//         vector<bool> visited(n,false);
//         dfs(g, i,i, visited);
//         for(int j=0;j<n;j++)
//         {
//             if(visited[j])
//                 g[i][j]=1;
//         }
//     }
// }
// void bfs(vector<vector<int>>& g, int start, int ori,vector<bool>& visited) {
//     queue<int> q;
//     q.push(start);
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         if (!visited[u]) {
//             if(u!=ori)
//                 visited[u] = true;
//             for (int i = 0; i < g.size(); i++) {
//                 if (g[u][i] && !visited[i]) {
//                     q.push(i);
//                 }
//             }
//         }
//     }
// }

// void computeReacheable(vector<vector<int>>& g) {
//     int n = g.size();
//     for (int i = 0; i < n; i++) {
//         vector<bool> visited(n, false);
//         bfs(g, i,i, visited);
//         for (int j = 0; j < n; j++) {
//             if (visited[j]) {
//                 g[i][j] = 1;
//             }
//         }
//     }
// }
void computeReachable(vector<vector<int>>& g) {
    int n = g.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin>>n;
    vector<vector<int>> g(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>g[i][j];
        }
    }
    computeReachable(g);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << g[i][j] << (j == n-1 ? "\n" : " ");
        }
    }
    return 0;
}
