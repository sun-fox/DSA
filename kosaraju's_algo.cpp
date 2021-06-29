//GeeksForGeeks: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    void DFS(int node, stack<int> &s, vector<bool> &vis, vector<int> adj[]){
        vis[node]=true;
        for(auto i: adj[node]){
            if(!vis[i])
                DFS(i,s,vis,adj);
        }
        s.push(node);
    }
    
    void DFS_rev(int node, vector<bool> &vis, vector<int> rev[]){
        vis[node]=true;
        for(auto i: rev[node]){
            if(!vis[i])
                DFS_rev(i,vis,rev);
        }
    }
    
	public:
    int kosaraju(int V, vector<int> adj[])
    {
        
        vector<bool> vis(V,false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i])
                DFS(i,s,vis,adj);
        }
        
        vector<int> rev[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                rev[adj[i][j]].push_back(i);
            }
        }
        
        for(int i=0;i<V;i++)
            vis[i]=false;
        int scc=0;
        
        while(!s.empty()){
            int top=s.top();
            s.pop();
            if(!vis[top]){
                scc++;
                DFS_rev(top,vis,rev);
            }
        }
        return scc;
    }
};
