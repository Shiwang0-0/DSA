

// Backtracking
// create a visited matrix and mark from were you are coming and avoid going back there until the recusrive call is returned because of base case. Change the state of visited matrix's cells to inital state each time you ends the sub-recursive calls.

// class Solution{
    
//     public:
    
//     bool isSafe(vector<vector<int>>m, int n, string &path, vector<string> &ans, int x, int y, vector<vector<int>> &visited)
//     {
//         if(x<0 || y<0 || x >= n || y >= n || visited[x][y]==1 || m[x][y]==0)
//             return 0;
            
//         return 1;
//     }
    
//     void solve(vector<vector<int>>m, int n, string &path, vector<string> &ans, int x, int y, vector<vector<int>> &visited)
//     {
//         if(x == n-1 && y == n-1)
//         {
//             ans.push_back(path);
//             return;
//         }
        
//         visited[x][y]=1;
        
//         // RIGHT
//         if(isSafe(m,n,path,ans,x,y+1,visited))
//         {
//             path.push_back('R');
//             solve(m,n,path,ans,x,y+1,visited);
//             path.pop_back();
//         }
        
//         //DOWN
//         if(isSafe(m,n,path,ans,x+1,y,visited))
//         {
//             path.push_back('D');
//             solve(m,n,path,ans,x+1,y,visited);
//             path.pop_back();
//         }
        
//         //UP
//         if(isSafe(m,n,path,ans,x-1,y,visited))
//         {
//             path.push_back('U');
//             solve(m,n,path,ans,x-1,y,visited);
//             path.pop_back();
//         }
        
//         //LEFT
//         if(isSafe(m,n,path,ans,x,y-1,visited))
//         {
//             path.push_back('L');
//             solve(m,n,path,ans,x,y-1,visited);
//             path.pop_back();
//         }
        
//         visited[x][y]=0;
//     }
    
    
//     vector<string> findPath(vector<vector<int>> &m, int n) {
//         vector<string>ans;
//         string path = "";
        
//         if(m[0][0]==0)
//         {
//             ans.push_back("-1");
//             return ans;
//         }
        
//         vector<vector<int>> visited(n,vector<int>(n,0));
        
//         // x and y coordinates as 0,0.
//         solve(m,n,path,ans,0,0,visited);
        
//         sort(ans.begin(),ans.end());
//         if(ans.size()==0)
//         {
//             ans.push_back("-1");
//             return ans;
//         }
//         return ans;
//     }
// };
