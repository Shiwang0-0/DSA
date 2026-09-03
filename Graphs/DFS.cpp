// #include <bits/stdc++.h>
// #include<vector>
// #include<queue>
// using namespace std;

// // Function to return Depth First Traversal of given graph.
// void dfsOfGraph(int node,vector<int> adj[],vector<int>&dfs,int vis[])
// {
//     // STARTING THE TRAVERSAL FROM NODE 1
//     vis[node] = 1; // also there is no 0th value, so start from 1st
//     dfs.push_back(node);
//     for(auto it:adj[node])
//     {
//         if(vis[it]!=1)
//             dfsOfGraph(it,adj,dfs,vis);
//     }
// }

// void printAns(vector<int> &ans)
// {
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     // adjacency list for undirected graph
//     // time complexity: O(2E)
//     vector<int> adj[n+1]; // iam taking 9 nodes and 9 edges, and one of the node is 9 so there should be matrix of 10*10. 
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     vector<int>dfs(0,0);
//     int vis[n+1] = {0};
//     dfsOfGraph(1,adj,dfs,vis);
//     printAns(dfs);


//     // IF GRAPHS ARE UN-CONNECTED THEN pass every node one time in loop, and then call dfs.
//     // This ensures that node from 1 to n each gets into DFS function atleast one time, and then its depth can be traversed.
//     /*
//     for(int i=0;i<=n;i++)
//         {
//             if(!vis[i])
//             {
//                 dfs(adjList,vis,i);
//                 c++;
//             }   
//         }
//     */

//     return 0;
// }


/*

9
9
1 2
1 6
2 3
2 4
6 7
6 9
4 5
7 8
5 8

*/

