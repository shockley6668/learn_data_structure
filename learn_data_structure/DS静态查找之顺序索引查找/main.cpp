//
//  main.cpp
//  DS静态查找之顺序索引查找
//
//  Created by Shockley on 12/7/23.
//

#include <iostream>
#include <vector>
using namespace std;
struct block {
    int max;
    int end;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,k,t;
    while (cin>>n) {
        vector<int> arr(n+1,0);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin>>k;
        vector<block> indexTable(k);
        for(int i=0;i<k;i++)
        {
            cin>>indexTable[i].max;
        }
        int j=0;
        for(int i=0;i<k;i++)
        {
            
            while (j<n) {
                if(arr[j]<=indexTable[i].max&&(j+1)!=n)
                {
                    j++;
                }
                else{
                    if((j+1)==n)
                    {
                        indexTable[i].end=j;
                    }
                    else
                        indexTable[i].end=j-1;
                    break;
                }
            }
        }
        cin>>t;
        while (t--) {
            int target;
            cin>>target;
            int count=0;
            int i=0;
            for(;i<k;i++)
            {
                count++;
                if(target>indexTable[i].max)
                {
                    
                }
                else{
                    break;
                }
            }
            i--;
            int b;
            b=i<0?0:indexTable[i].end+1;
            for(;b<=n;b++)
            {
                count++;
                if(arr[b]==target)
                {
                    break;
                }
            }
            if(b>indexTable[i+1].end)
            {
                cout<<"error"<<endl;
            }
            else{
                cout<<b+1<<"-"<<count<<endl;
            }
        }
    }
    
    return 0;
}

