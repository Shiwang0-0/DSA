class Solution
{
    
    private:
        int prims(vector<pair<int,int>>adjList[],vector<int>&vis)
        {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,0});
            int sum=0;
            while(!pq.empty())
            {
                int wt=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                if(vis[node]==1)
                    continue;
                vis[node]=1;
                sum=sum+wt;
                
                for(auto it:adjList[node])
                {
                    int cost=it.second;
                    int ele=it.first;
                    if(vis[ele]==0)
                    {
                        pq.push({cost,ele}); // you just push the cost you see for reaching the next code from the current node
                        // dont need to add the previous path cost, because what matters is only this cost (thats how prims works)
                    }
                }
            }
            return sum;
        }
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,int>>adjList[V];
        for (int i = 0; i < V; i++) {
        for (auto edge : adj[i]) {
            int to = edge[0];
            int weight = edge[1];
            adjList[i].push_back({to, weight});
        }
    }
        
        vector<int>vis(V,0);
        return prims(adjList,vis);
    }
};