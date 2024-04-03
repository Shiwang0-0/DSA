
/*

ROTTING ORANGES

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.



class Solution {
public:

    int bfs(queue<pair<pair<int,int>,int>>&q,int time,vector<vector<int>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        int timeMaxi=0;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            time=q.front().second;
            q.pop();
            int neighbourRow[4]={-1,0,1,0};
            int neighbourCol[4]={0,1,0,-1};
            timeMaxi=max(time,timeMaxi);
            for(int i=0;i<4;i++)
            {
                int row=x+neighbourRow[i];
                int col=y+neighbourCol[i];
                if(row>=0 && row<m && col>=0 && col<n && grid[row][col]==1)
                {
                    grid[row][col]=2;
                    // time=time+1; dont do this this will change time for every loop
                    q.push({{row,col},time+1});// with respect to same time, time is incremented
                }
            }
        }
        return timeMaxi;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // prefer sending all the rotten oranges int the queue first beacuse they will all have time=0 on the other hand when sending oranges in a for loop the time they take might get distured  because we are modifying the main matrix itself even if we create visited it will get modifed because thats what we need to do.
        
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0}); // they all will take 0 time
                }
            }
        }

        int time = bfs(q,0,grid);
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

        return time;
    }
};



P.S: Instead of the last 2 for loops, it can also be solved by comparing noOfFreshOranges initially, and noOfOrangesWeHaveMadeRotten during the entire process.

*/