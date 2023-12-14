//
//  main.cpp
//  E : 图综合练习--拓扑排序
//
//  Created by Shockley on 11/22/23.
//

#include <iostream>
using namespace std;
const int MAXN=1000;
int graph[MAXN][MAXN];
int inDegree[MAXN]={0};
int queue[MAXN];
int front=0,rear=0;
void enqueue(int x)
{
    queue[rear++]=x;
}
int dequeue()
{
    return queue[front++];
}
bool isEmpty()
{
    return front==rear;
}
void topological_sort(int n)
{
    for(int i=0;i<n;i++ )
    {
        if(inDegree[i]==0)
        {
            enqueue(i);
        }
    }
    while (!isEmpty())
    {
        int u=dequeue();
        cout<<u<<" ";
        for(int v=0;v<n;v++)
        {
            if(graph[u][v])
            {
                graph[u][v]=0;
                if(--inDegree[v]==0)
                {
                    enqueue(v);
                }
            }
        }
    }
    cout<<endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>graph[i][j];
                if(graph[i][j])
                {
                    inDegree[j]++;
                }
            }
        }
        topological_sort(n);
    }
    return 0;
}
