// Hint: you have to connect the components , therefore disjoint sets 


/*

class Solution {

private:

    int findUltParent(int node,vector<int>&parent)
    {
        if(parent[node]==node)
            return node;
        return parent[node]=findUltParent(parent[node],parent);
    }

    int connect(int u,int v,vector<int>&parent,vector<int>&size)
    {
        int extraEdges=0;
        int ultU=findUltParent(u,parent);
        int ultV=findUltParent(v,parent);
        if(parent[ultU]==parent[ultV]) // parent same of 2 nodes
        {
            extraEdges++;  // means that parent would already be reacheable by some other edge
            // who marked it at first time.
            // so this current edge is useless for now and can be used fro connecting the components.
            return extraEdges;
        }
        if(size[ultU]>size[ultV])
        {
            parent[ultV]=ultU;
            size[ultU]=size[ultU]+size[ultV];
        }
        else
        {
            parent[ultU]=ultV;
            size[ultV]=size[ultU]+size[ultV];
        }
        return extraEdges;
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // you cannot just make imaginary edges,
        // you have to take some pre-existing edge and then connect the graphs.

        // try making components but should have minimum edges used.
        // disjoint sets
        int ans=0,totalExtraEdges=0;
        vector<int>parent(n,0);
        vector<int>size(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        // all weights are 1 no need to sort
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            totalExtraEdges=totalExtraEdges+connect(u,v,parent,size); // count extra edges
            // these are the ones using whihc we will connect the components
        }
        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]==i) // if parent of i is same as i means that is top node of the "component"
            // means we get a component
                ans++;
        }
        if(totalExtraEdges>=ans-1) // C number of components requires C-1 edges to join (minimum)
        // so we check do we have enough edges that we can connect all the components.
        {
            return ans-1;
        }
        return -1;
    }
};

*/