// #include <bits/stdc++.h>
// #include<vector>
// #include<queue>
// using namespace std;

// // Function to return Breadth First Traversal of given graph.
// vector<int> bfsOfGraph(int V, vector<int> adj[])
// {
//     int vis[V] = {0}; 

//     // STARTING THE TRAVERSAL FROM NODE 1
//     vis[1] = 1; // also there is no 0th value, so start from 1st
//     queue<int> q;
//     q.push(1);
//     vector<int> bfs;
//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();
//         bfs.push_back(node);
//         for (auto it : adj[node])
//         {
//             if (!vis[it])
//             {
//                 vis[it] = 1;
//                 q.push(it);
//             }
//         }
//     }
//     return bfs;
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

//     vector<int> ans = bfsOfGraph(n+1, adj);
//     printAns(ans);

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
