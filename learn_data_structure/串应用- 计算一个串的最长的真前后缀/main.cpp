//
//  main.cpp
//  串应用- 计算一个串的最长的真前后缀
//
//  Created by Shockley on 10/12/23.
//

#include <iostream>
#include <string.h>
using namespace std;
void GetNext(string p, int next[]) {
    int j = 0;
    int k = -1;
    int L = (int)p.length();
    next[0] = -1;

    while (j < L - 1) {
        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}
string matched_Prefix_Postfix(string p){
//    int *next=new int((int)p.length());
    
    int j = 0;
    int k = -1;
    int L = (int)p.length();
    int *next=new int[L+1];
    next[0] = -1;
    int max=0;
    while (j < L ) {
        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;
            next[j] = k;
            
        } else {
            k = next[k];
        }
        
    }
    
    for(int i=0;i<L+1;i++)
    {
        if(max<next[i])
            max=next[i];
    }
    
    string ans;
    if (next[L]==0)
        ans="empty";
    else
        ans=p.substr(0,next[L]);
    return ans;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        cout<<matched_Prefix_Postfix(s)<<endl;
        
    }
    return 0;
}
