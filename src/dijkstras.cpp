#include "dijkstras.h"
#include <algorithm>

// Implements Dijkstra's algorithm to find the shortest path from a source vertex
vector<int> dijkstra_shortest_path(const Graph& graph, int source, vector<int>& previous) 
{
    int numVertices = graph.numVertices;
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distances[source] = 0;  
    previous.assign(numVertices, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;  
    minHeap.push({0, source});

    while (!minHeap.empty()) 
    {
        int u = minHeap.top().second;
        minHeap.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& edge : graph[u]) 
        {
            int v = edge.dst;
            int weight = edge.weight;

            if (!visited[v] && distances[u] + weight < distances[v]) 
            {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({distances[v], v});
            }
        }
    }
    
    return distances;
}


// Extracts the shortest path from the previous nodes array
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) 
{
    vector<int> path;
    for (int v = destination; v != -1; v = previous[v]) 
    {
        path.push_back(v);
    }

    std::reverse(path.begin(), path.end());
    return path;
}

// Prints the shortest path and its total cost
void print_path(const vector<int>& path, int total) 
{
    for (int v : path) cout << v << " -> ";
    cout << "Total cost: " << total << endl;
}
