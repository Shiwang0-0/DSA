/*
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

APPROACH: Choose one element, then two element and so on in recursive call.



class Solution {
public:

    bool isPalin(string sub,int start,int end)
    {
        for(int i=start,j=end;i<=j && j>=start;i++,j--)
        {
            if(sub[i]!=sub[j])
                return false;
        }
        return true;
    }

    void solve(vector<string>temp,vector<vector<string>>&ans,string s,int i)
    {
        if(i==s.length())
        {
           ans.push_back(temp);
           return;
        }
        for(int j=i;j<s.length();j++)
        {
            
            // string sub=s.substr(i,j-i+1);
            // int end=sub.length()-1;
            // if(isPalin(sub,0,end))
            // {
            
            // or choose this 
            // if you dont want to calculate sub everytime (even if it will fail the condition of being a palindrome in the next line)
            if(isPalin(s,i,j))
            {
                string sub=s.substr(i,j-i+1);
                temp.push_back(sub);
                solve(temp,ans,s,j+1); // j+1 because of loop
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        solve(temp,ans,s,0);
        return ans;
    }
};
*/