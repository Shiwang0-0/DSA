/*

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.


class Solution {

private:
    void bfs(queue<pair<pair<int,int>,int>>q,vector<vector<int>>& mat,vector<vector<int>>& vis,vector<vector<int>>& dist)
    {
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            int count=q.front().second;
            vis[x][y]=1;
            dist[x][y]=count;
            q.pop();

            vector<int>neiRow={0,1,0,-1};
            vector<int>neiCol={1,0,-1,0};

            for(int i=0;i<4;i++)
            {
                int row=neiRow[i]+x;
                int col=neiCol[i]+y;
                if(row>=0 && row<mat.size() && col>=0 && col<mat[0].size() && !vis[row][col])
                {
                    vis[row][col]=1;
                    if(mat[row][col]!=0)
                    {
                        q.push({{row,col},count+1});
                    }
                }
            }
        }
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // nearest zero dekhne hai
        // 0 se nearest 0 zero hi hoga, to push it anyways.
        // jab 1 aae mat mai tabh bfs call kero, taki 1 se nearest 0 mil sake.


        // we will need a visited array, kyuki agar vo abhi mark hua mtlb abhi vala pheli baar tha jab vo mark hua.. mtlb iske aage ab kabhi bhi mark nahi hosakta vo.. mtlb hume nearest distance hi milega.
        int m=mat.size();
        int n=mat[0].size();

        vector<vector<int>> vis( m , vector<int> (n,0));  
        vector<vector<int>> dist( m , vector<int> (n,0));  
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        bfs(q,mat,vis,dist);

        return dist;

    }
};

*/