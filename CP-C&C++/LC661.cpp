// Image Smoother
// An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells).

// class Solution {
// public:
//     vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
//         int m=img.size();
//         int n=img[0].size();
//         vector<vector<int>>ans(m,vector<int>(n,0));
//         int sum=0,x=0,k=0,temp=0,count=0;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 sum=0,temp=0,count=0;
//                 for(x=i-1;x<=i+1;x++)
//                 {
//                     for(k=j-1 ;k<=j+1;k++)
//                     {
                        
//                         if(x<0 || k<0 || x>=m || k>=n)
//                         {
//                             continue;
//                         }
//                         count++;
//                         sum=sum+img[x][k];
//                     }
//                 }
//             temp=sum/count;
//             ans[i][j]=temp;
            
//             }
//         }
//         return ans;
//     }
// };