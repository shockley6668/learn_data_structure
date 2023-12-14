//
//  main.cpp
//  DS图遍历--广度优先搜索
//
//  Created by Shockley on 11/13/23.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void BFS(int start,vector<vector<int>>& graph,vector<bool> &visited)
{
    queue<int> q;
    visited[start]=true;
    q.push(start);
    while (!q.empty()) {
        int current=q.front();
        q.pop();
        cout<<current<<" ";
        for(int i=0;i<graph.size();i++)
        {
            if(graph[current][i]==1&&visited[i]==false)
            {
                q.push(i);
                visited[i]=true; //广度优先搜索在入队时标记访问,在for循环遍历邻居时
            }
        }
        
    }
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
        vector<bool> visited(graph.size(),false);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>graph[i][j];
            }
        }
        for (int i=0; i<n; i++) {
            if(!visited[i])
                BFS(i, graph,visited);
        }
        cout << endl;

    }

    return 0;

}
