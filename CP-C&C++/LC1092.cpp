// Shortest Common Supersequence 

// how do you find the length of the resultant sequenece
// s1.length + s2.length - no of common subsequence

// because s1.length + s2.length will give the longest super string.
// we  have to remove those who are repeating and count them only once to get the shortest one.

// imagine final dp table for getting the string.

/*

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        

        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<m;i++)
        {
            dp[0][i]=0;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }

        // Length of final subsequence
        // int len=n+m-dp[n][m];
        // cout<<len;

        string ans="";
        // backtrack
        while(n>0 && m>0)
        {
            if(s1[n-1]==s2[m-1])
            {
                ans+=s1[n-1];  // n-1 for indexes purpose
                n--;
                m--;
            }
            else if(dp[n-1][m]>dp[n][m-1]) // left is greater
            {
                ans+=s1[n-1];  // row will move up, so include rows corresponsing ele
                n--;
            }
            else
            {
                ans+=s2[m-1]; // col will move left, so include cols corresponsing ele
                m--;
            }
        }

        // check if still n>0 or m>0
        while(n>0)
        {
            ans+=s1[n-1];
            n--;
        }

        while(m>0)
        {
            ans+=s2[m-1];
            m--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};

*/