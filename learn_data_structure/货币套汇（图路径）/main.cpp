//
//  main.cpp
//  货币套汇（图路径）
//
//  Created by Shockley on 11/23/23.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int T;
    cin>>T;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        vector<string> currency(n);
        map<string,int> currencyIndex;
        for(int i=0;i<n;i++)
        {
            cin>>currency[i];
            currencyIndex[currency[i]]=i;
        }
        vector<vector<double>> rates(n,vector<double>(n,0));
        //储存汇率
        for(int i=0;i<m;i++)
        {
            string from,to;
            double rate;
            cin>>from>>rate>>to;;
            rates[currencyIndex[from]][currencyIndex[to]]=rate;
        }
        //floyd算法
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                {
                    rates[i][j]=max(rates[i][j],rates[i][k]*rates[k][j]);//插点
                }
            }
        }
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(rates[i][i]>1)
            {
                flag=true;
                break;
            }
        }
        cout<<(flag?"YES":"NO")<<endl;

    }
    
    return 0;
}
