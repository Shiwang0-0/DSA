/*

void shortestPathAlgo(vector<int>&dist,int src, vector<pair<int,int>>adjList[])
{
    int distance=1;
        for(auto it:adjList[src])
        {
            int ele=it.first;
            int wt=it.second;
            distance=dist[src]+wt;
            if(dist[ele] > distance)
            {
                dist[ele]=distance;
            }
    }
}

void topoSort(int node, vector<pair<int,int>>adjList[],int vis[],stack<int>&st)
{
    vis[node]=1;
    for(auto it:adjList[node])
    {
        int ele=it.first;
        if(!vis[ele])
        {
            topoSort(ele,adjList,vis,st);
        }
    }
    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{

    vector<pair<int,int>>adjList[n];
    for(int i=0;i<edges.size();i++)
    {
        adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
    }

    // topo sort
    int vis[n]={0};
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            topoSort(i,adjList,vis,st);
        }
    }

    int val=1e9;
    vector<int>dist(n,val);
    dist[0]=0;

    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        shortestPathAlgo(dist,node,adjList); // no need of queue now 
        // because we already know that i will come before i+1 always as stack came from topo sort.
    }

    vector<int>ans;
    
    for(int i=0;i<dist.size();i++)
    {
        if(dist[i]!=val)
            ans.push_back(dist[i]);
        else   
            ans.push_back(-1);
    }

    return ans;

}
*/