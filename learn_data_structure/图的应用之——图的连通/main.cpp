//
//  main.cpp
//  图的应用之——图的连通
//
//  Created by Shockley on 11/15/23.
//

#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    static const size_t MAX_SIZE = 100; // 栈的最大容量
    T data[MAX_SIZE];
    size_t topIndex; // 栈顶索引

public:
    Stack() : topIndex(0) {}
    // 入栈
    void push(const T& value) {
        if (topIndex == MAX_SIZE) {
            throw std::overflow_error("Stack overflow");
        }
        data[topIndex++] = value;
    }

    // 出栈
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        return data[--topIndex];
    }

    // 获取栈顶元素
    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return data[topIndex - 1];
    }

    // 检查栈是否为空
    bool isEmpty() const {
        return topIndex == 0;
    }

    // 获取栈的大小
    size_t size() const {
        return topIndex;
    }
};


void DFS(int start,int graph[100][100],bool* visited,int n)
{
   
    Stack<int> s;
    s.push(start);
    while(!s.isEmpty())
    {
        int top=s.top();
        s.pop();
        
        if(visited[top]==false)
        {
            
            visited[top] = true;  //深度优先搜索在出栈时标记访问

        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(graph[top][i]==1&&visited[i]==false) //如果有边且未访问
            {
                s.push(i);
            }
                
        }
    }

}

int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int graph[100][100];
        int reversegraph[100][100];
        bool visited[100]={0};
        bool reversevisited[100]={0};
//        memset(visited, 0, 100);
//        memset(reversevisited, 0, 100);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>graph[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                reversegraph[j][i]=graph[i][j];
            }
        }
        DFS(0, graph, visited,n);
        DFS(0, reversegraph, reversevisited,n);
        bool f=false;
        for (int i=0; i<n; i++) {
            if(visited[i]==0||reversevisited[i]==0)
            {
                f=true;
            }
        }
        if(f)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;

    }

    return 0;
}

