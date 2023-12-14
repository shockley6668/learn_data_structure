//
//  main.cpp
//  DS静态查找之顺序查找
//
//  Created by Shockley on 12/7/23.
//

#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
int arr[maxn];
int main() {
    // insert code here...
    int n;
    cin>>n;
    while (cin>>n) {
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        int t;
        cin>>t;
        while (t--) {
            int num;
            cin>>num;
            arr[0]=num;
            int i=n;
            for(i=n;arr[i]!=num;i--);
            if(i!=0)
            {
                cout<<i<<endl;
            }
            else
            {
                cout<<"error"<<endl;
            }
        }
    }
    
    return 0;
}
