#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

template <typename T>
class Graph
{
public:
    map<T, list<pair<T, int>>> adjList;

    void addEdge(T v1, T v2, int distance, bool bidirectional = 1)
    {
        adjList[v1].push_back(make_pair(v2, distance));

        if (bidirectional)
            adjList[v2].push_back(make_pair(v1, distance));
    }

    void printAdjList()
    {
        for (auto elem : adjList)
        {
            cout << elem.first << " : ";
            for (auto pair : elem.second)
            {
                cout << "(" << pair.first << ", "
                     << pair.second
                     << ")";
            }
            cout << endl;
        }
    }

    /*
    Time complexity: O(V + E), where V is the number of vertices
            and E is the number of edges in the graph.
    Space Complexity :O(V).
            Since an extra visited array is needed of size V.
     */
    void dfsUtility(T srcVertex, map<T, bool> &visited)
    {
        visited[srcVertex] = true;
        cout << srcVertex << " -> ";

        for (auto vertex : adjList[srcVertex])
        {
            if (visited[vertex.first])
                ;
            else
            {
                dfsUtility(vertex.first, visited);
            }
        }
    }

    void depthFirstSearch(T srcVertex)
    {
        map<T, bool> visited;
        dfsUtility(srcVertex, visited);
        cout << "X" << endl;
    }
};

int main()
{
    Graph<char> graph;
    graph.addEdge('0', '1', 4, 0);
    graph.addEdge('1', '7', 11, 0);
    graph.addEdge('1', '2', 8, 0);
    graph.addEdge('7', '8', 7, 0);
    graph.addEdge('2', '8', 2, 0);
    graph.addEdge('8', '6', 6, 0);
    graph.addEdge('6', '5', 2, 0);

    char v1 = '1';
    cout << "Depth First Search from vertex " << v1 << ": ";
    graph.depthFirstSearch(v1);

    cout << "Adjacency list of graph is : \n";
    graph.printAdjList();

    return 0;
}