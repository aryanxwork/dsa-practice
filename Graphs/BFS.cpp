#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int V, vector<int> adj[])
{
    queue<int> q;
    vector<bool> vis(V, false);
    q.push(0);
    vis[0]=true;
    while (!q.empty())
    {
        int front = q.front();
        cout<<front<<" ";
        q.pop();
        for (auto it : adj[front])
        {
            if (vis[it] != true)
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }
}
int main()
{
    int n, m; // n=number of nodes m=number of edges
    cout << "Enter number of Nodes - ";
    cin >> n;
    cout << "Enter number of Edges - ";
    cin >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cout << "Enter first edge  - ";
        cin >> u;
        cout << "Enter second edge - ";
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}