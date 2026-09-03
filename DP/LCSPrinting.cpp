#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


  int funcDP(vector<vector<int>>&dp, string &text1, string &text2, int i, int j)
    {
        if(i<0 || j<0 )
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(text1[i]==text2[j])
            return 1+funcDP(dp,text1,text2,i-1,j-1);

        return dp[i][j]=0+max(funcDP(dp,text1,text2,i-1,j),funcDP(dp,text1,text2,i,j-1));
    }

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
        vector<vector<int>>dp(m,vector<int>(n,-1));

        int len=funcDP(dp,s1,s2,m-1,n-1);

		string ans;
		int i=0,j=0;
				while(i<m && j<n)
                {
                    
                    if(s1[i]==s2[j])
                    {
                        ans.push_back(s1[i]);
                        i++;
                        j++;
                    }
                    else if(i+1<m && j+1<n && dp[i+1][j]>dp[i][j+1])
                    {
                        i++;
                    }
                    else 
                    {
                        j++;
                    }
                }
             return ans;
		}


int main()
{
    string s;
    string s1="ldxgoohkumo";
    string s2="cqyxwraowfz";




    s=findLCS(11,11,s1,s2);
    cout<<s;
    return 0;
}