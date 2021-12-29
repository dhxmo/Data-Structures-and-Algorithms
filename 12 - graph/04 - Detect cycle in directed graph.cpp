/* 
Given a directed graph, check whether the graph contains a cycle or not. 
Your function should return true if the given graph contains at least one cycle, else return false.
*/

#include <iostream>
#include <list>
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool recStack[]);

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v);

    bool isCyclic();
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

/* 
DFS modified
Time Complexity: O(V+E). 
Space Complexity: O(V), 
            To store the visited and recursion stack O(V) space is needed.
*/
bool Graph::isCyclicUtil(int v, bool visited[], bool recStack[])
{
    if (visited[v] == false)
    {
        // mark nodes as visited
        visited[v] = true;
        recStack[v] = true;

        // recur for adjacent vertices
        list<int>::iterator it;
        // check adjacent nodes of the present node
        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            // if node hasn't been visited
            if (!visited[*it] && isCyclicUtil(*it, visited, recStack))
                return true;
            // else if already visited, check if vertex is in the recursion stack
            else if (recStack[*it])
                return true;
        }
    }
    // if no cycle found
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic()
{
    // initialize visited array and recall stack; populate false
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // iterate through the vertices
    for (int i = 0; i < V; i++)
    {
        // pass each node through cycle detecting DFS function
        if (isCyclicUtil(i, visited, recStack))
            return true;
    }
    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph doesn't contain a cycle" << endl;

    return 0;
}