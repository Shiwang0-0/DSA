// Given an m x n binary matrix mat, return the number of special positions in mat.

// A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

// Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
// Output: 1
// Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.


// class Solution {
// public:
//     int numSpecial(vector<vector<int>>& mat) {
//         int n=mat.size();
//         int m=mat[0].size();
//         int ans=0;
//         int c=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 c=0;
//                 if(mat[i][j]==1)
//                 {
//                     for(int x=0;x<m;x++)
//                     {
//                         if(mat[i][x]==1)
//                         {
//                             c++;
//                         }
//                     }
//                     if(c!=1)
//                     {
//                         break;
//                     }
//                     for(int x=0;x<n;x++)
//                     {
//                         if(mat[x][j]==1)
//                         {
//                             c++;
//                         }
//                     }
//                     // if(c!=2)
//                     // {
//                     //     break;
//                     // }
//                 }
//                 if(c==2)
//                 {
//                     ans++;
//                 }  
//             }
//         }
//         return ans;
//     }
// };