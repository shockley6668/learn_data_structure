//
//  main.cpp
//  DS图遍历--深度优先搜索
//
//  Created by Shockley on 11/13/23.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(int start,vector<vector<int>>&graph,vector<bool> &visited)
{
   
    stack<int> s;
    s.push(start);
    while(!s.empty())
    {
        int top=s.top(); 
        s.pop();
        
        if(visited[top]==false) 
        {
            cout << top << " ";
            visited[top] = true;  //深度优先搜索在出栈时标记访问

        }
        
        for(int i=graph[top].size()-1;i>=0;i--)
        {
            if(graph[top][i]==1&&visited[i]==false) //如果有边且未访问
            {
                s.push(i);
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
                DFS(i, graph,visited);
        }
        cout << endl;

    }

    return 0;
}
