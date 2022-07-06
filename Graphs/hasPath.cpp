#include <bits/stdc++.h>
using namespace std;

bool hasPath_DFS(int **edges, int n, int v1, int v2, bool *visited)
{
    visited[v1] = true;
    if (edges[v1][v2] == 1)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == v1)
        {
            continue;
        }
        if (edges[v1][i] == 1)
        {
            if (visited[i])
                {
                    continue;
                }

            if (hasPath_DFS(edges, n, i, v2, visited))
                {
                    return true;
                }
        }
    }

    return false;
}

bool hasPathDFS(int **edges, int n, int v1, int v2)
{
    bool *visited = new bool[n];
    return hasPath_DFS(edges, n, v1, v2, visited);
}

int main()
{  

    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int first, second;
        cin >> first >> second;

        for (int j = 0; j < e; j++)
        {
            edges[first][second] = 1;
            edges[second][first] = 1;
        }
    }

    cout<<hasPathDFS(edges,n,1,6)<<endl;    

    return 0;
}