//
//  main.cpp
//  F : B DS图_课程表
//
//  Created by Shockley on 11/22/23.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool canFinish(int numCourse,vector<vector<int>>& prerequesties)
{
    vector<int> inDegree(numCourse,0);
    vector<vector<int>> graph(numCourse);
    for(auto& pre:prerequesties)
    {
        graph[pre[1]].push_back(pre[0]);
        ++inDegree[pre[0]];
    }
    queue<int> q;
    for(int i=0;i<numCourse;i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        --numCourse;
        for(auto& next:graph[curr])
        {
            if(--inDegree[next]==0)
                q.push(next);
        }
    }
    return numCourse==0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        int len;
        cin>>n>>len;
        vector<vector<int>> prerequesties(len,vector<int>(2));
        for(int i=0;i<len;i++)
        {
            cin>>prerequesties[i][0]>>prerequesties[i][1];  
        }
        cout << (canFinish(n, prerequesties) ? "true" : "false") << endl;

    }
    
    return 0;
}
