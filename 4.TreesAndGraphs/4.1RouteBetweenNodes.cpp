// Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a
// route between two nodes.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>>Adj;
public:
    Graph(int V);
    void addEdge(int v,int w); //edge from v to w
    bool routeExists(Graph G,int start,int end);
};

Graph::Graph(int V){
    this->V=V;
    this->Adj=vector<vector<int>>(V);
}
void Graph::addEdge(int v,int w){
    Adj[v].push_back(w);
}

//basically using bfs to check if that node has been reached from our node
bool Graph::routeExists(Graph g,int start,int end){
    vector<bool>visited(V,false);
    visited[start]=true;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        start=q.front();
        q.pop();
        for(int i=0;i<Adj[start].size();i++)
        {
            if(!visited[Adj[start][i]])
            {
                visited[Adj[start][i]]=true;
                q.push(Adj[start][i]);
            }
        }

    }
    if(visited[end]==true){
        return true;
    }else{
        return false;
    }
}

int main(){
    Graph g(5); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    // g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.addEdge(1,4);
    cout<<g.routeExists(g,0,3)<<endl;
    cout<<g.routeExists(g,2,4);
}