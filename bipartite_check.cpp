//GeeksForGeeks: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool dfs(int node, vector<int> adj[], vector<int> &color, int marker){
    //     color[node]=marker;
    //     bool ans = true;
    //     for(auto i : adj[node])
    //         if(color[i]==-1){
    //                 ans = dfs(i,adj,color,(marker==0)?1:0);
    //                 break;
    //             }
    //         else if(color[i]==color[node]){
    //             ans=false;
    //             break;
    //         }
    //     return ans;
    // }
    
    bool dfs(int node, vector<int> adj[], vector<int> &color, int marker){
        color[node]=marker;
        for(auto i : adj[node])
            if(color[i]==-1){
                if(!dfs(i,adj,color,1-marker))
                    return false;
            }
            else if(color[i]==color[node])
                return false;
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for(int i=0;i<V;i++)
	        if(color[i]==-1)
    	        if(!dfs(i,adj,color,0))
    	            return false;
	    return true; 
	}
};