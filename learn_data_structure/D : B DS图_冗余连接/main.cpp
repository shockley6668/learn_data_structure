//
//  main.cpp
//  D : B DS图_冗余连接
//
//  Created by Shockley on 11/22/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n=edges.size();
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++)
        parent[i]=i;
    function<int(int)> find=[&](int x){
            if(x!=parent[x]) //如果x不是根节点
            {
                parent[x]=find(parent[x]); // 路径压缩,递归调用find将x的父节点设为根节点,
            }
            return parent[x];
    };
    for(auto &edge:edges)
    {
        int u=edge[0],v=edge[1];
        int pu=find(u),pv=find(v);
        if(pu==pv)
            return edge;
        else
            parent[pu]=pv;
    }
    return {};
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> edges(n);
        for(int i=0;i<n;i++)
        {
            edges[i].resize(2);
            cin>>edges[i][0]>>edges[i][1];
        }
        vector<int> ans=findRedundantConnection(edges);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
