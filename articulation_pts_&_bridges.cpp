#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> bridges;
vector<int> artcl_pts;

void dfs(int node, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<int> &parent){
    static int timer=0;
    disc[node]=low[node]=timer;
    timer++;

    int children = 0;
    for(auto v : adj[node]){
        if(disc[v]==-1){
            children+=1;
            parent[v]=node;
            dfs(v,adj,disc,low,parent);
            low[node]=min(low[node],low[v]);

            if(parent[node]==-1 && children>1)
                artcl_pts.push_back(node);
            if(parent[node]!=-1 && low[v]>=disc[node])
                artcl_pts.push_back(node);
            if(low[v]>disc[node])
                bridges.push_back(make_pair(node,v));
        }
        else if(parent[node]!=v){
            low[node]=min(low[node],disc[v]);
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,x,y;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<n;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> disc(n,-1), low(n,-1), parent(n,-1);

    for(int i=0;i<n;i++){
        if(disc[i]==-1){
            dfs(i,adj,disc,low,parent);
        }
    }
    cout<<artcl_pts.size()<<endl;
    sort(artcl_pts.begin(),artcl_pts.end());
    for(auto i: artcl_pts)
        cout<<i<<" ";
    cout<<endl;  
    cout<<bridges.size()<<endl;
    sort(bridges.begin(),bridges.end());
    for(auto p: bridges)
        cout<<p.first<<" "<<p.second<<endl; 
    return 0;
}
