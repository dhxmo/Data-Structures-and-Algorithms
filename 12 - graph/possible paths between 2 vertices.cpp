/* 
Given a Directed Graph. Count the total number of ways or paths that exist between 
two vertices in the directed graph. These paths doesn’t contain any cycle.
Note: Graph doesn't contain multiple edges, self loop and cycles and 
the two vertices( source and destination) are denoted in the example.
*/

#include <iostream>
#include <vector>
#include <queue>
#define V 5
#define E 7
using namespace std;

// instantiate the adjacency list and add edges
vector<int> adjList[V];

void addEdge(int v1, int v2)
{
    adjList[v1].push_back(v2);
}

// Function to count paths between two vertices in a directed graph.
int countPaths(vector<int> adj[], int source, int destination)
{
    // base case
    // if source reaches destination once return 1
    if (source == destination)
        return 1;

    int count = 0;
    queue<int> q;

    // push first vertex to que
    q.push(source);

    // BFS
    while (!q.empty())
    {
        // assign variable to first vertex and pop from que
        int temp = q.front();
        q.pop();

        // iterate over edges in the adjacency list
        for (auto x : adj[temp])
        {
            // if edge found, increment count
            if (x == destination)
                count++;
            // else add to que for next evaluation
            else
                q.push(x);
        }
    }

    return count;
}

int main()
{
    int total_vertices = V;
    int total_edges = E;
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 4);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 2);

    int source = 0;
    int destination = 2;
    cout << "Total paths from " << source << " to " << destination << " in the given graph = "
         << countPaths(adjList, source, destination) << endl;

    return 0;
}