//
//  main.cpp
//  子串循环问题 (Ver. I)
//
//  Created by Shockley on 10/12/23.
//

#include <iostream>
using namespace std;
void getNext(const string &p,int *next)
{
    int L=(int)p.length();
    int j=0;
    int k=-1;
    next[0]=-1;
    while (j<L) {
        if(k==-1||p[k]==p[j])
        {
            j++;
            k++;
            next[j]=k;
        }
        else
            k=next[k];
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        int len=(int)s.length();
        int *next=new int[len+1];
        getNext(s, next);
        int T=len-next[len];
        
        if(next[len]==0)
        {
            cout<<len<<endl;
        }
        else if(len%T==0)
        {
            cout<<0<<endl;
        }
        else{
            cout<<T-(len%T)<<endl;
        }
        
    }
    return 0;
}

