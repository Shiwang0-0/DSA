#include <bits/stdc++.h>

void dfs(int node,vector<int>adj[],int vis[],stack<int>&st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,st);

        }
    }
    st.push(node);
}

 

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int>adj[nodes];
    for(auto it:graph)
    {
        adj[it[0]].push_back(it[1]);
    }
    int vis[nodes]={0};
    stack<int>st;
    for(int i=0;i<nodes;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis,st);
        }
    }
    vector<int>ans;
    for(int i=0;i<nodes;i++)
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}