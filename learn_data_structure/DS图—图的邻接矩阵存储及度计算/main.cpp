//
//  main.cpp
//  DS图—图的邻接矩阵存储及度计算
//
//  Created by Shockley on 11/9/23.
//
#include <iostream>
using namespace std;
class Map{
public:
    char type;
    char size;
    int **matrix;
    string* vertices;
    Map(char t,int s):type(t),size(s){
        matrix=new int*[s];
        for(int i=0;i<s;i++)
        {
            matrix[i]=new int[s];
            for(int j=0;j<s;j++)
            {
                matrix[i][j]=0;
            }
        }
        vertices=new string[size];
        
    }
    void setVertices()
    {
        for(int i=0;i<size;i++)
        {
            cin>>vertices[i];
        }
    }
    int getIndex(string c)
    {
        for(int i=0;i<size;i++)
        {
            if(c==vertices[i])
                return i;
        }
        return -1;
    }
    void setMap()
    {
        string from,to;
        int t;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            cin>>from>>to;
            if(type=='D')
            {
                matrix[getIndex(from)][getIndex(to)]=1;
            }
            if(type=='U')
            {
                int fromIndex=getIndex(from);
                int toIndex=getIndex(to);
                matrix[fromIndex][toIndex]=1;
                matrix[toIndex][fromIndex]=1;
            }
        }
    }
    void PrintMap()
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                cout<<matrix[i][j];
                if(j!=size-1)
                {
                    cout<<" ";
                }
            }
            cout<<endl;
       
        }
    }
    void printAllDegree()
    {
        if(type=='D')
        {
            int** allDegree=new int*[size];
            for(int i=0;i<size;i++)
            {
                allDegree[i]=new int [2];
                allDegree[i][0]=0;
                allDegree[i][1]=0;
            }
            
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    if(matrix[i][j]==1)
                        allDegree[i][0]++;
                    if(matrix[j][i]==1)
                    {
                        ++allDegree[i][1];
                    }
                    
                }
                
            }
            for(int i=0;i<size;i++){
                cout<<vertices[i]<<": ";
                if((allDegree[i][1]+allDegree[i][0])!=0)
                    cout<<allDegree[i][0]<<" "<<allDegree[i][1]<<" "<<(allDegree[i][1]+allDegree[i][0]);
                cout<<endl;
            }
            
        }
        if(type=='U')
        {
            int* allDegree=new int[size];
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    if(matrix[i][j]==1)
                        allDegree[i]++;
                }
                
            }
            for(int i=0;i<size;i++){
                cout<<vertices[i]<<": ";
                if(allDegree[i]!=0)
                    cout<<allDegree[i];
                cout<<endl;
            }
        }
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char type;
        int size;
        cin>>type>>size;
        Map map(type,size);
        map.setVertices();
        map.setMap();
        map.PrintMap();
        map.printAllDegree();
    }
    

}
