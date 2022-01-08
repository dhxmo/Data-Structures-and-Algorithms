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

    void breadthFirstSearch(T v1)
    {
        map<T, bool> visited;
        // FIFO data structure
        queue<T> que;
        // push first vertex into que
        que.push(v1);

        while (!que.empty())
        {
            // assign the front vertex to a variable
            T frontVertex = que.front();
            // pop the vertex out the que
            que.pop();

            if (!visited[frontVertex])
            {
                // print the vertex
                cout << frontVertex << " -> ";
                visited[frontVertex] = true;
            }

            for (auto edge : (adjList[frontVertex]))
            {
                if (!visited[edge.first])
                    que.push(edge.first);
            }
        }
        cout << "X\n";
    }
};

int main()
{
    Graph<char> graph;
    graph.addEdge('0', '1', 4, 0);
    graph.addEdge('1', '7', 11, 0);
    graph.addEdge('1', '2', 8, 1);
    graph.addEdge('7', '8', 7, 0);
    graph.addEdge('2', '8', 2, 0);
    graph.addEdge('8', '6', 6, 0);
    graph.addEdge('6', '5', 2, 1);

    char v1 = '8';
    cout << "Breadth First Search from vertex " << v1 << ": ";
    graph.breadthFirstSearch(v1);

    cout << "Adjacency list of graph is : \n";
    graph.printAdjList();

    return 0;
}