//HackerEarth: https://www.hackerearth.com/problem/algorithm/kruskals-3f35730e/

#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,wt;
    node(int first, int second, int weight){
        a = first;
        b = second;
        wt = weight;
    }
};

bool comparator(node a, node b){
    return a.wt<b.wt;
}

//Find Parent along side doing path compression
int FindParent(int vertice, vector<int> &parent){
    if(parent[vertice]==vertice) return vertice;
    return parent[vertice] = FindParent(parent[vertice],parent);
}

//Union: connect to different components
void Union(int a, int b, vector<int> &parent, vector<int> &rank){
    a = FindParent(a, parent);
    b = FindParent(b, parent);
    if(rank[a]>rank[b])
        parent[b]=a;
    else if(rank[b]>rank[a])
        parent[a]=b;
    else{
        parent[a]=b;
        rank[b]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,e;
    cin>>n>>e;

    vector<node> edges;
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(node(u,v,w));
    }
    sort(edges.begin(),edges.end(),comparator);

    vector<int> parent;
    vector<int> rank(n, 0);
    for(int i=0;i<n;i++){
        parent.push_back(i);
    }

    vector<pair<int,int>> mst;
    int cost=0;

    for(auto edge:edges){
        if(FindParent(edge.a, parent)!=FindParent(edge.b, parent)){
            Union(edge.a,edge.b,parent,rank);
            cost+=edge.wt;
            mst.push_back(make_pair(edge.a,edge.b));
        }
    }
    
    cout<<cost<<endl;

    return 0;
}