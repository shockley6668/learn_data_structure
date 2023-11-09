//
//  main.cpp
//  图综合练习--构建邻接表
//
//  Created by Shockley on 11/9/23.
//

#include <iostream>
#include <list>
#include "algorithm"
using namespace std;
struct Vertex{
    char info;
    list<int> adjList;
};
class adjacencyList
{
public:
    vector<Vertex> vertices;
    void addEdge(int from,int to)
    {
        vertices[from].adjList.push_back(to);
    }
    
    void printAdjacencyList()
    {
        for(int i=0;i<vertices.size();i++)
        {
            cout<<i<<" "<<vertices[i].info<<"-";
            for(int neighbor:vertices[i].adjList)
            {
                cout<<neighbor<<"-";
            }
            cout << "^" << endl;
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
    cin>>t;
    while (t--) {
        int n,k; //// 顶点数量和边数量
        cin>>n>>k;
        adjacencyList graph;
        for(int i=0;i<n;i++)
        {
            Vertex vertex;
            cin>>vertex.info;
            graph.vertices.push_back(vertex);
        }
        for(int i=0;i<k;i++)
        {
            char from,to;
            cin>>from>>to;
            auto fromIt=find_if(graph.vertices.begin(), graph.vertices.end(),
                                  [from](const Vertex& v){return v.info==from;});
            auto toIt = find_if(graph.vertices.begin(), graph.vertices.end(),
                                  [to](const Vertex& v) { return v.info == to; });
            
            int fromIndex=(int)distance(graph.vertices.begin(), fromIt);
            int toIndex=(int)distance(graph.vertices.begin(), toIt);
            graph.addEdge(fromIndex, toIndex);
        }
        graph.printAdjacencyList();
    }
    return 0;
}
