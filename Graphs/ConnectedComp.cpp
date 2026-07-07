#include<iostream>
#include<vector>
using namespace std;
void dfs(int node,vector<int>adj[],vector<bool>&vis){
    vis[node]=true;
    for(auto it : adj[node]){
        if (vis[it]!=true)
        {
            vis[it]=true;
            dfs(it,adj,vis);
        }
        
    }
}
int connectedcomp(int V,vector<int>adj[]){
    vector<bool>vis(V,false);
    int count=0;
    vis[1]=true;
    for (int i = 1; i <= V; i++)
    {
        if (vis[i]!=true)
        {
            count++;
            dfs(i,adj,vis);

        }
        
    }
    return count;
    
}
int main()
{
    int n, m; // n=number of nodes m=number of edges
    cout << "Enter number of Nodes - ";
    cin >> n;
    cout << "Enter number of Edges - ";
    cin >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter first edge  - ";
        cin >> u;
        cout << "Enter second edge - ";
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<connectedcomp(n,adj);
}