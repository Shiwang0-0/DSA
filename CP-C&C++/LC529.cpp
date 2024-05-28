class Solution {


// helpful comment in discussion

// I know that this question was posted long time ago. But just in case someone else wondered about it. [0,2] should not be 1 in the output. As it stated in the problem description, "If an empty square 'E' with no adjacent mines is revealed, then change it to a revealed blank 'B' and all of its adjacent unrevealed squares should be revealed recursively."
// I will try to explain it in a BFS way. In the given example, click is [3, 0], it can reveal its 3 neighbors, [[2, 0], [2, 1], [3, 1]] because there is no mine around it. Then, [2, 0] can reveal its 2 neighbors, [[1, 0], [1, 1]]. We will keep doing this. When we reach [0, 1], it will not reveal [0, 2] because there is a mine around it.


private:
    void bfs(vector<vector<char>>& board, vector<int>& click)
    {
        queue<pair<int,int>>q;
        q.push({click[0],click[1]});
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int count=0;


        // since the highest priority is of finding a mine, 
        // if mine is found no dare someone can change it, 
        // and also the mine adj holds the character value of number of mines.

            // counting mines
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int neiX=x+i;
                    int neiY=y+j;
                    if(neiX>=0 && neiX<board.size() 
                    && neiY>=0 && neiY<board[0].size() && board[neiX][neiY]=='M')
                    // if a mine is found in adj regions
                    // you dont search the adj regions
                    {
                        count++;
                    }
                }
            }
            if(count>0) // marking number of mines if mineCount>0 in adj regions
            {
                board[x][y]=count+'0';
            }
            else // if mineCount in adj regions is 0 then it will be Blank.
            // and you are ready to search more blocks.
            {
                board[x][y]='B'; // make sure to mark current block as Blank.
                for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                        int neiX=x+i;
                        int neiY=y+j;
                        if(neiX>=0 && neiX<board.size() 
                        && neiY>=0 && neiY<board[0].size() 
                        && board[neiX][neiY]=='E')
                        {
                                board[neiX][neiY]='B';
                                q.push({neiX,neiY});
                        }
                    }
                }
            }     
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

        int c0=click[0];
        int c1=click[1];
        if(board[c0][c1]=='M')
            board[c0][c1]='X';
            
        else
            bfs(board,click);

        return board;
    }
};