#include <bits/stdc++.h>
using namespace std;

bool issafe(int node,int col,vector<int>adj[],vector<int>&color){
    for(auto neighbours: adj[node]){
        if(color[neighbours]==col){
            return false;
        }
    }
    return true;
}
bool mColoring(int node,int V,int m,vector<int>adj[],vector<int>&color){
    if(node==V){
        return true;
    }
    for(int col=0;col<m;col++){
        if(issafe(node,col,adj,color)){
            color[node]=col;
        
        if(mColoring(node+1,V,m,adj,color)){
            return true;
        }
        color[node]=-1;
    }
    
}
return false;
}
int main() {
	int V,E,m;
	cin>>V>>E>>m;
	vector<int>adj[V];
	for(int i=0;i<E;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	vector<int>color(V,-1);
	if(mColoring(0,V,m,adj,color)){
	    cout<<"Yes"<<endl;
	    for(int i=0;i<V;i++){
	        cout<<color[i]<<" ";
	    }
	}
	else{
	    cout<<"No"<<endl;
	}
}
