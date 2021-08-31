/* A simple representation of graph using STL */
#include <iostream>
#include <map>
#include <list>
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
};

// Driver code
int main()
{
    Graph<char> g;

    g.addEdge('1', '1', 4, 0);
    g.addEdge('0', '7', 8, 0);
    g.addEdge('1', '7', 11, 0);
    g.addEdge('1', '2', 8, 0);
    g.addEdge('7', '8', 7, 1);
    g.addEdge('2', '8', 2, 1);
    g.addEdge('8', '6', 6, 0);
    g.addEdge('2', '5', 4, 1);
    g.addEdge('6', '5', 2, 0);
    g.addEdge('2', '3', 7, 1);
    g.addEdge('3', '3', 14, 1);
    g.addEdge('3', '4', 9, 0);
    g.addEdge('5', '4', 10, 0);
    g.addEdge('7', '6', 1, 0);

    g.printAdjList();

    return 0;
}