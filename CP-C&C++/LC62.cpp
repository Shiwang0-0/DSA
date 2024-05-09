/*

MEMOIZATION

class Solution {

private:
    int funcDP(vector<vector<int>>&dp,vector<vector<int>>&grid,int row,int col,int m,int n)
    {
        if(row==m-1 && col==n-1)
        {
            return 1;
        }
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        int move=0,sum=0;
        vector<int>neiRowRight={1,0};
        vector<int>neiColBot={0,1};
        for(int i=0;i<2;i++)
        {
            int neiRow=row+neiRowRight[i];
            int neiCol=col+neiColBot[i];

            if(neiRow>=0 && neiRow<m && neiCol>=0 && neiCol<n)
            {
                move+=funcDP(dp,grid,neiRow,neiCol,m,n);
            }
            sum=move;
        }
        return dp[row][col]=sum;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<vector<int>> grid(m, vector<int>(n, -1));
        return funcDP(dp,grid,0,0,m,n);
    }
};
*/




/*
TABULATION

intution: movement start to 0,0 se hogi, lekin usko chaiye kya .. uske pichle vale..
means argar right and down maimove ker sakta hu... uskp chaiye left and up vale ( previous hoga jo) uski value.

class Solution {

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)  
            { 
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                    continue;
                }
                // since iam starting from 0,0 and this is tabulation i need to know the previous ones.
            // as i will increment it will calculate them and those will be used in future.
                int up=0,left=0;
                if(i-1>=0)
                    up=dp[i-1][j]; // uper se aaya (mtlb niche aaya)
                if(j-1>=0)
                    left=dp[i][j-1]; // left se aaya ( mtlb right mai aaya)
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};
*/


/*

SPACE OPTIMIZATION

class Solution {

public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0); // prev is the one iam updating and making with every change in row.
        for(int i=0;i<m;i++)
        {
            vector<int>curr(n,0); // curr is the current one which will have changes according to the prev.
            for(int j=0;j<n;j++)
            {

                if(i==0 && j==0)
                {
                    curr[j]=1; // you are computing the current row.
                    continue;
                }

                int fromUp=0,fromLeft=0;
                    fromUp=prev[j];

                if(j-1>=0)
                    fromLeft=curr[j-1];

                curr[j]=fromUp+fromLeft;
            }
            prev=curr;
        }
        return prev[n-1];
    }
};

*/




