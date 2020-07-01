// Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of
// projects, where the second project is dependent on the first project). All of a project's dependencies
// must be built before the project is. Find a build order that will allow the projects to be built. If there
// is no valid build order, return an error.
// EXAMPLE
// Input:
// projects: a, b, c, d, e, f
// dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
// Output: f, e, a, b, d, c
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>>Adj;
public:
    Graph(int V);
    void addEdge(int v,int w); //edge from v to w
    vector<char>findBuildOrder();
    void helper(int s,vector<bool>&visited,stack<int>&stack);
};

Graph::Graph(int V){
    this->V=V;
    this->Adj=vector<vector<int>>(V);
}
void Graph::addEdge(int v,int w){
    Adj[v].push_back(w);
}
// void Graph::DFS_util(int s,vector<bool>visited)
// {
//     visited[s]=true;
//     cout<<s<<" ";
//     for(int i=0;i<adj[s].size();i++)
//             if(!visited[adj[s][i]])
//                 DFS_util(adj[s][i],visited);   
// }

// void Graph::DFS(int s)
// {
//     vector<bool>visited(V,false);
//     DFS_util(s,visited);
// }

// method 1 is to find the node with no incoming links and store it and then remove it fom the graph
// then go to the next element with no incoming links

//method 2 is to just use DFS and store the element first reached in a stack cause 
//that is going to be the element that is last reached
void Graph::helper(int s,vector<bool>&visited,stack<int>&stack){
    visited[s]=true;
    for(int i=0;i<Adj[s].size();i++)
        if(!visited[Adj[s][i]])
            helper(Adj[s][i],visited,stack); 

    //after an element is found in dfs its index is stored
    stack.push(s);
}

vector<char>Graph::findBuildOrder(){
    vector<bool>visited(V,false);
    stack<int>stack;

    //need to call dfs for all nodes who are yet to be visited cause although some nodes are not connected
    //they are still a part of build order
    for(int i=0;i<V;i++)
        if(!visited[i])
            helper(i,visited,stack);

    vector<char>result;
    
    while(!stack.empty()){
        result.push_back(stack.top()+'A');
        stack.pop();
    }
    return result;
}

int main(){
    Graph g(7);
    g.addEdge(5,1); //f->b
    g.addEdge(5,2); //f->c
    g.addEdge(2,0); //c->a
    g.addEdge(1,0); //b->a
    g.addEdge(0,4); //a->e
    g.addEdge(1,4); //b->e
    g.addEdge(3,6); //d->g

    vector<char>result=g.findBuildOrder();
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

}