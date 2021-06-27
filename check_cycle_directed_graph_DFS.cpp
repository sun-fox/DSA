//GeeksForGeeks: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	
	bool check_cycle(int n, vector<int> adj[], vector<int> &vis, vector<int> &dfs_vis){
	    vis[n]=true;
	    dfs_vis[n]=true;
	    for(int i=0;i<adj[n].size();i++){
	       if(!vis[adj[n][i]]){
	           if(check_cycle(adj[n][i],adj,vis,dfs_vis)) return true;
	       }
	       else if(dfs_vis[adj[n][i]]){
	           return true;
	       }
	    }
	    dfs_vis[n]=false;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, false);
	    vector<int> dfs_vis(V, false);
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(check_cycle(i,adj,vis,dfs_vis))
	                return true;
	        }
	    }
	    return false;
	}
};