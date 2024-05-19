//Minimum Insertion Steps to Make a String Palindrome

// SOLVE 516. Longest Palindromic Subsequence
// IT TELLS YOU HOW TO FIND LONGEST PALINDROMIC SUBSEQUENCE


// INTUTION
// Here we we use the same approach and remove the common subsequences (between string s and its reverse string t ) from the length n, we will get length of characters which are not common in the palindrome, and those we have to change or actually inser.

// because if b,d are two characters which are not in longest palindromic subsquence, we will need d,b 2 new characters which will pair with b,d.


/*

class Solution {
public:
    int minInsertions(string s) {
    string t=s;
        reverse(t.begin(), t.end());
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};

*/