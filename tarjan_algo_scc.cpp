//Question: https://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs(int node, vector<int>adj[], vector<vector<int>>&ans,
        vector<int>&low, vector<int>&discov, stack<int>&s, vector<bool>&instack, int &timer) {
        
        discov[node] = low[node] = timer;
        timer++;
        s.push(node);
        instack[node] = true;
        for (auto v : adj[node]) {
            if (discov[v] == -1) {
                dfs(v, adj, ans, low, discov, s, instack, timer);
                low[node] = min(low[v], low[node]);
            }
            else if (instack[v]) {
                low[node] = min(low[node], discov[v]);
            }
        }
        
        if (low[node] == discov[node]) {
            vector<int>scc;
            while (s.top() != node && !s.empty()) {
                scc.push_back(s.top());
                instack[s.top()] = false;
                s.pop();
            }
            if (!s.empty()) {
                scc.push_back(s.top());
                instack[s.top()] = false;
                s.pop();
                // sort(scc.begin(), scc.end());
                ans.push_back(scc);
            }
        }
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        vector<vector<int>>ans;
        stack<int>s;
        vector<int>low(V, -1);
        vector<int>discov(V, -1);
        vector<bool>instack(V, false);
        int timer =0;
        for (int i = 0; i < V; i++) {
            if (discov[i] == -1)
                dfs(i, adj, ans, low, discov, s, instack, timer);
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends