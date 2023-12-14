//
//  main.cpp
//  DS图—图的连通分量
//
//  Created by Shockley on 11/15/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int n, const vector<vector<int>>& matrix) : numVertices(n), adjacencyMatrix(matrix) {}

    int countConnectedComponents() {
        vector<bool> visited(numVertices, false);
        int components = 0;

        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i]) {
                dfs(i, visited);
                components++;
            }
        }

        return components;
    }
//递归
    void dfs(int vertex, vector<bool>& visited) {
        visited[vertex] = true;

        for (int i = 0; i < numVertices; ++i) {
            if (adjacencyMatrix[vertex][i] && !visited[i]) {
                dfs(i, visited);
            }
        }
    }
};

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<string> vertices(n);
        vector<vector<int>> matrix(n, vector<int>(n));

        for (int j = 0; j < n; ++j) {
            cin >> vertices[j];
        }

        int m;
        cin >> m;

        for (int j = 0; j < m; ++j) {
            string v1, v2;
            cin >> v1 >> v2;

            int index1 = find(vertices.begin(), vertices.end(), v1) - vertices.begin();
            int index2 = find(vertices.begin(), vertices.end(), v2) - vertices.begin();

            matrix[index1][index2] = 1;
            matrix[index2][index1] = 1;
        }

        Graph graph(n, matrix);

        // 输出顶点信息和邻接矩阵信息
        for (int j = 0; j < n; ++j) {
            cout << vertices[j] << " ";
        }
        cout << endl;

        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cout << matrix[j][k] << " ";
            }
            cout << endl;
        }

        // 输出连通分量个数
        cout << graph.countConnectedComponents() << endl;

        // 输出空行分隔
        if (i != t - 1) {
            cout << endl;
        }
    }

    return 0;
}
