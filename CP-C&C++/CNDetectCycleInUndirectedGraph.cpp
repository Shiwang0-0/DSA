/*

BFS APPROACH

class Graph {

private:
    bool bfs(int V, vector<int>adj[],vector<int>&vis,queue<pair<int,int>>&q,int i)
    {
        vis[i]=1;
        q.push({i,-1}); // no parent of the first node
        while(!q.empty())
        {
            int node=q.front().first; 
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]) // find childrens of node in adj list
            {
                if(!vis[it]) // if not visited mark them as visited
                {
                    vis[it]=1;
                    q.push({it,node}); 
                    
                    // yaha node pass hua, parent nahi, kyuki jo abhi ka node hai vo aage jake kisi ka parent banega, to parent ko hi vapis bejhne ka sense banta ni.
                }         
                else if(parent!=it) 
                // if already visited, jo abhi abhi popped vale ka parent tha, vo abhi abhi pushed vala element hai tabh to chalo koi baat nahi kyuki hume vapis vahi element "undirected vali condition" se milgya ki 1->2 hai to 2->1 hai..
                // lekin agar parent piche ke "travelled path" se nahi lekin kahi aage ke unknown path pe aa mila, to loop h
                    return true;
            }
        }
        return false;
    }

public:
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        vector<int>vis(V,0);
        queue<pair<int,int>>q; // <source node, its parent>
        for(int i=0;i<V;i++) // for non-connected components
        {
            if(!vis[i])
            {
                if(bfs(V,adj,vis,q,i))
                    return true;
            }
        }
        return false;
    }
};


*/



/*
DFS APPROACH

class Graph {

private:
    bool dfs(vector<int> adj[], int V,vector<int>&visited,pair<int,int>p) // <node,parent>
    {
        int node=p.first;
        int parent=p.second;
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it]!=1)
            {
                // visited[it]=1;  
                if(dfs(adj,V,visited,{it,node}))  
                    return true;
            }
            else if(parent!=it)
                return true;
                
        }
        return false;
    }

public:
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        for(int i=0;i<V;i++)
        {
            vector<int>visited(V,0);
            if(dfs(adj,V,visited,{1,-1}))
                return true;
        }
        return false;
    }
};
*/
