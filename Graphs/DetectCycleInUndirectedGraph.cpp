#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adj;
    bool isCyclicUtil(int v, bool visited[],int parent){
        visited[v] = true;

        list<int>::iterator i;

        for(i=adj[v].begin(); i!=adj[v].end(); i++){
            if(!visited[*i]){
                if( isCyclicUtil(*i,visited,v) ){
                    return true;
                }
            }

            else if(*i != parent ){
                return true;
            }
        }

        return false;
    }

    public:
        Graph(int V){
            this->V = V;
            adj = new list<int>[V];
        }


        void addEdge(int v, int w){
            adj[v].push_back(w);                    //adding edges via adjacency list
        }

        bool isCyclic(){
            bool* visited = new bool[V];

            for(int i=0;i<V;i++){
                visited[i]=false;
            }

            //call the function to detect cycles
            for(int i=0;i<V;i++){
                if(!visited[i]){                            //don't reccur for 'i' if already visited
                    if( isCyclicUtil(i, visited, -1) ){
                        return true;
                    }
                }
            }
            return false;
        }
};


int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic() ? cout << "Graph contains cycle\n"
                  : cout << "Graph doesn't contain cycle\n";
 
    return 0;
}