//Question: https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    
    int Tarjan_DFS(int &scc, int node, vector<int> *adj, vector<int> &discov, vector<int> &low, vector<int> &instack, int &time, stack<int> &s){
        if(discov[node]==-1){
            discov[node]=time;
            low[node]=time;
            time++;
        }
        s.push(node);
        instack[node]=true;
        
        for(auto v : adj[node]){
            if(discov[v]==-1){
                Tarjan_DFS(scc,node,adj,discov,low,instack,time,s);
                low[node]= min(low[node],low[v]);
            }
            else if(instack[node]){
                low[node]=min(low[node],discov[v]);
            }
        }
        //Check if head node
        if(low[node]==discov[node]){
            scc++;
            while(s.top()!=node){
                instack[s.top()]=false;
                s.pop();
            }
            instack[s.top()]=false;
            s.pop();
        }
        return scc;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n && i!=j;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> discov(n,-1);    // Discovery time of the node
        vector<int> low(n,-1);       // Lowest Insertion Time 
        vector<int> instack(n,false);
        
        stack<int> s;
        int time = 0;
        int scc = 0;
        
        for(int i=0;i<n;i++){
            if(discov[i]==-1)
                Tarjan_DFS(scc,i,adj,discov,low,instack,time,s);
        }
        
        return scc;
    }
};