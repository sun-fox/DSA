//GeeksForGeeks: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> cost(V, INT_MAX);
        vector<bool> vis(V, false);
        vector<int> parent(V, -1);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            
            vis[node]=true;
            for(auto edge:adj[node]){
                int vertice = edge[0];
                int edge_cost = edge[1];
                if(cost[vertice]> edge_cost && vis[vertice]==false){
                    parent[vertice]= node;
                    cost[vertice]= edge_cost;
                    pq.push(make_pair(cost[vertice],vertice));
                }
            }
        }
        
        int res=0;
        for(int i=1;i<V;i++){
            res+=cost[i];
        }
        return res;
    }
    
};