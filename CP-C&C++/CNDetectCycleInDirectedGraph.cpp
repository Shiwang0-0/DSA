
/*
bool dfs(vector<int>adjList[], int v, int e,int node,vector<int>&vis,vector<int>&pathVis)
{
	vis[node]=1;
	pathVis[node]=1;
	for(auto it:adjList[node])
	{
		if(pathVis[it]==1 && vis[it]==1) // yar abhi to mai is path se uspe gya ni.. lekin vo pehele se hi visited hai
		{
			return true;
		}

		if(vis[it]==0)
		{	
			if(dfs(adjList,v,e,it,vis,pathVis))
			{
				return true;
			}
		}
		
	}
	pathVis[node]=0; // present node ki hi baat ker ki uska pathVis 0 ho jae.. kyu ?
	// agar present ka hogya to baki ander valo pe jaega ni,
	// agar ander vale ka pathVis 1 hone ka dar hai to vo hoga ni kabhi kyuki backtrack kerte hue 0 ho rah h
	return false;
}


bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
		vector<int>vis(v,0);
		vector<int>pathVis(v,0);
		vector<int>adjList[v];
		for(int i=0;i<e;i++)
		{
			adjList[edges[i][0]].push_back(edges[i][1]);
		}
		for(int i=0;i<v;i++)
		{
			if(vis[i]==0 )
			{
				if(dfs(adjList,v,e,i,vis,pathVis))
				return true;
			}
		}	
	return false;
}
*/

// ---------------------------------------------------------------------------------------------------------------

/*  Without using adj List


bool dfs(vector<vector<int>>&edges, int v, int e,int node,vector<int>&vis,vector<int>&pathVis)
{
	vis[node]=1;
	pathVis[node]=1;
	for(int i=0;i<edges.size();i++)
	{
		if(node==edges[i][0])  // [row][0] vala element already marked in first 2 lines, we needs its connected node which will be [row][1], so use it as the it node
		{
			int it=edges[i][1];
			if(pathVis[it]==1) // yar abhi to mai is path se uspe gya ni.. lekin vo pehele se hi visited hai
			{
				return true;
			}
			if(vis[it]==0)
			{	
				if(dfs(edges,v,e,it,vis,pathVis))
				{
					return true;
				}
			}
		}	
	}

	pathVis[node]=0; // present node ki hi baat ker ki uska pathVis 0 ho jae.. kyu ?
	// agar present ka hogya to baki ander valo pe jaega ni,
	// agar ander vale ka pathVis 1 hone ka dar hai to vo hoga ni kabhi kyuki backtrack kerte hue 0 ho rah h
	return false;
}


bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
		vector<int>vis(v,0);
		vector<int>pathVis(v,0);
		for(int i=0;i<v;i++)
		{
			if(vis[i]==0 )
			{
				if(dfs(edges,v,e,i,vis,pathVis))
				return true;
			}
		}	
	return false;
}

*/