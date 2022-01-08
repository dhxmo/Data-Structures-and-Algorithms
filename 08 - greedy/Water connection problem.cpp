/* Every house in the colony has at most one pipe going into it and at most one pipe 
going out of it. Tanks and taps are to be installed in a manner such that every house 
with one outgoing pipe but no incoming pipe gets a tank installed on its roof and every 
house with only an incoming pipe and no outgoing pipe gets a tap.

Given two integers n and p denoting the number of houses and the number of pipes. 
The connections of pipe among the houses contain three input values: 
ai, bi, di denoting the pipe of diameter di from house ai to house bi. 
Find the efficient way for the construction of the network of pipes.

The output will contain the number of pairs of tanks and taps t installed in first line 
and the next t lines contain three integers: house number of tank, house number of tap 
and the minimum diameter of pipe between them. */

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void dfs(int node, vector<pair<int, int>> colony[], int &minDiameter, int &nextNode, int visited[])
{
    // node is marked as visited
    visited[node] = 1;

    // iterate over its neighbours
    for (auto connectionAndWeight : colony[node])
    {
        // if neighbour is not visited yet
        if (visited[connectionAndWeight.first] == 0)
        {
            // find diameter of the pipe
            minDiameter = min(minDiameter, connectionAndWeight.second);
            // set next house to check its neighbour in colony and run dfs recursively
            nextNode = connectionAndWeight.first;
            dfs(connectionAndWeight.first, colony, minDiameter, nextNode, visited);
        }
    }
}

vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
{
    // list of visited nodes in the graph and populate the array
    int visited[n + 1];
    memset(visited, 0, sizeof(visited));

    vector<vector<int>> ans;

    // vectors to hold value of pipes going in and out of houses
    // initiate value false
    vector<int> in(n + 1, 0);
    vector<int> out(n + 1, 0);

    // graph representing the colony
    vector<pair<int, int>> colony[n + 1];
    for (int i = 0; i < p; i++)
    {
        // populate out[] with houses with outgoing pipes
        out[a[i]] = 1;

        // populate in[] with houses with incoming pipes
        in[b[i]] = 1;

        // update graph network
        colony[a[i]].push_back({b[i], d[i]});
    }

    // iterate over the houses and run a dfs to follow pipe connections
    for (int i = 1; i <= n; i++)
    {
        // no incoming and has an outgoing pipe which hasn't been visited
        if (in[i] == 0 && out[i] == 1 && visited[i] == 0)
        {
            // current house
            int s = i;
            // the next house
            int neighbour;
            // count minimum pipe diameter
            int minDiameter = INT16_MAX;

            dfs(i, colony, minDiameter, neighbour, visited);
            cout << s << " " << neighbour << " " << minDiameter << endl;

            ans.push_back({s, neighbour, minDiameter});
        }
    }

    return ans;
}

// Driver code
int main()
{
    int n = 9, p = 6;
    // a contains houses with outgoing pipes
    vector<int> a = {7, 5, 4, 2, 9, 3};
    // b contains houses with incoming pipes
    vector<int> b = {4, 9, 6, 8, 7, 1};
    // diameter of pipes
    vector<int> d = {98, 72, 10, 22, 17, 66};

    solve(n, p, a, b, d);

    return 0;
}