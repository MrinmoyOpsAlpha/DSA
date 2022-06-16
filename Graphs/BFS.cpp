#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<list<int>> adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

// defining the constructor
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

// defining the function BFS
void Graph::BFS(int s)
{
    vector<bool> visited;
    visited.resize(V, false); // marking every initial element as unvisited

    list<int> queue;
    list<int>:: iterator it;

    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " "; // dequeuing a vertex from queue and printing it.
        queue.pop_front();

        for (it=adj[s].begin(); it!=adj[s].end(); it++)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                queue.push_back(*it);
            }
        }
    }
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

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}