//
//  main.cpp
//  DS队列--组队列
//
//  Created by Shockley on 10/11/23.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int findId(vector<vector<int>> &arr,int num)
{
    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<arr[i].size(); j++) {
            if(num==arr[i][j])
                return i;
        }
    }
    return -1;
}
int main()
{
    int t,s;
    cin>>t;
    vector<vector<int>> arr(t);
    for (int i=0; i<t; i++) {
        cin>>s;
        arr[i]=vector<int>(s);
        for (int j=0; j<s; j++) {
            cin>>arr[i][j];
        }
    }
    string cmd;
    int num;
    queue<queue<int>*> groups;
    vector<queue<int>> group(t);
    int flag=0;
    while (cin>>cmd&&cmd!="STOP") {
        if(cmd=="ENQUEUE"){
            cin>>num;
            int index=findId(arr, num);
            if(index!=-1)
            {
                if(group[index].empty()){
                    group[index].push(num);
                    groups.push(&group[index]);
                }
                else{
                    group[index].push(num);
                }
            }
        }
        if(cmd=="DEQUEUE")
        {
            if(!groups.empty())
            {
                if(!groups.front()->empty())
                {
                    if(flag==1)
                        cout<<" ";
                    cout<<groups.front()->front();
                    groups.front()->pop();
                    if(groups.front()->empty())
                        groups.pop();
                }
                else {
                    
                    if(!groups.empty()&&!groups.front()->empty())
                    {
                        if(flag==1)
                            cout<<" ";
                        cout<<groups.front()->front();
                        groups.front()->pop();
                    }
                }
            }
        
            flag=1;
                
        }
    }
}

