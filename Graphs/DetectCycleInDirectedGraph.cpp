#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    bool isCyclicUtil(int v, bool visited[], bool *recStack)
    {
        if (!visited[v])
        {
            visited[v] = true;
            recStack[v] = true;
        }

        list<int>::iterator it;

        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (!visited[*it] && isCyclicUtil(*it, visited, recStack))
                return true;
            else if (recStack[*it])
                return true;
        }
        recStack[v] = false;
        return false;
    }

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    bool isCyclic()
    {
        bool *visited = new bool[V];
        bool *recStack = new bool[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            recStack[i] = false;
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (isCyclicUtil(i, visited, recStack))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}