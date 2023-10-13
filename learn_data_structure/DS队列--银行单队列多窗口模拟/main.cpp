//
//  main.cpp
//  DS队列--银行单队列多窗口模拟
//
//  Created by Shockley on 10/11/23.
//

#include <iostream>
#include <queue>
#include <iomanip>
#include <cstring>
struct custom{
    int T;
    int P;
};
using namespace std;
queue<custom> customs;
int main(int argc, const char * argv[]) {
    
    int t;
    cin>>t;
    for (int i=0; i<t; i++) {
        custom cus;
        cin>>cus.T>>cus.P;
        customs.push(cus);
    }
    int windows;
    cin>>windows;
    int* w=new int[windows];
    memset(w, 0, sizeof(int)*windows);
    int longestWaitTime=0;
    double totalWaitTime=0;
    while (!customs.empty()) {
        int flag=0;
        for(int i=0;i<windows;i++)
        {
            if(customs.front().T>=w[i])
            {
                w[i]=customs.front().T+customs.front().P;
                
                customs.pop();
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            int min=0;
            for(int i=0;i<windows;i++)
            {
                if(w[min]>w[i])
                    min=i;
            }
            if(w[min]-customs.front().T>longestWaitTime)
                longestWaitTime=w[min]-customs.front().T;
            totalWaitTime+=w[min]-customs.front().T;
            w[min]=customs.front().T+customs.front().P+w[min]-customs.front().T;
            customs.pop();
        }
    }
    int finalTime=0;
    for(int i=0;i<windows;i++)
    {
        if(finalTime<w[i])
        {
            finalTime=w[i];
        }
    }
    
    cout<< fixed<<setprecision(1)<<(totalWaitTime/t)<<" "<<longestWaitTime<<" "<<finalTime<<endl;
    return 0;
}
