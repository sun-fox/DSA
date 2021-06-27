//GeeksForGeeks: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool check_cycle(int n, int parent, vector<int> adj[], vector<int> &vis){
	    vis[n]=true;
	    for(int i=0;i<adj[n].size();i++){
	        if(!vis[adj[n][i]]){
	            if(check_cycle(adj[n][i],n,adj,vis)) 
	                return true;
	        }
	        else if(adj[n][i]!=parent){
	            return true;
	        }
	    }
	    return false;
	}
	
	bool isCycle(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V, false);
	   	for(int i=0;i<V;i++){
	   	    if(vis[i]==false){
	   	        if(check_cycle(i,-1,adj,vis))
	   	            return true;
	   	    }
	   	}
	   	
	   	return false;
	}
};