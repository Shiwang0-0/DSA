// Difference Between Ones and Zeros in Row and Column

// You are given a 0-indexed m x n binary matrix grid.

// A 0-indexed m x n difference matrix diff is created with the following procedure:

// Let the number of ones in the ith row be onesRowi.
// Let the number of ones in the jth column be onesColj.
// Let the number of zeros in the ith row be zerosRowi.
// Let the number of zeros in the jth column be zerosColj.
// diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
// Return the difference matrix diff.




// APPROACH 1 (TIME LIMIT EXCEEDED) O(N^3)

// class Solution {
// public:
//     vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>> diff(n,vector<int>(m,0));
//         int onesRow=0,onesCol=0,zerosRow=0,zerosCol=0,diffVal=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 onesRow=0,onesCol=0,zerosRow=0,zerosCol=0,diffVal=0;
//                 for(int x=0;x<n;x++)
//                 {
//                     if(grid[x][j]==1)
//                     {
//                         onesCol++;
//                     }
//                     else
//                     {
//                         zerosCol++;
//                     }
//                 }
//                 for(int y=0;y<m;y++)
//                 {
//                     if(grid[i][y]==1)
//                     {
//                         onesRow++;
//                     }
//                     else
//                     {
//                         zerosRow++;
//                     }
//                 }

//             diffVal=onesRow+onesCol-zerosRow-zerosCol;
//             diff[i][j]=diffVal;
//             }
//         }
//         return diff;
//     }
// };


// APPROACH 2 O(m*n)
// Keep storing the sum in array for rows and cols and then find the relation between the zeros for rows and cols and store it in the diff array for each.

// class Solution {
// public:
//     vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>>diff(m,vector<int>(n));
//         vector<int> rows(m);
//         vector<int> cols(n);
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 rows[i]=rows[i]+grid[i][j];
//                 cols[j]=cols[j]+grid[i][j];
//             }
//         }
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 diff[i][j]=2*(rows[i]+cols[j])-m-n;
//             }
//         }
//         return diff;
//     }
// };
