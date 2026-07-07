#include<iostream>
#include<vector>
using namespace std;

void dfshelper(int node,vector<int>adj[],vector<int>&ans,vector<bool>&vis){
    vis[node]=true;
    ans.push_back(node);
    for(auto it :adj[node]){
        if (vis[it]!=true)
        {
            dfshelper(it,adj,ans,vis);
        }
        
    } 
}
vector<int> dfs(int V,vector<int>adj[]){
    vector<bool>vis(V,false);
    vector<int>ans;
    int start=0;
    dfshelper(start,adj,ans,vis);
    return ans;
}