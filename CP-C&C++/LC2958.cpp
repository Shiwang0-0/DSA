/*

// SIMILAR QUESTION LC:3090

O(N^2)
Maximum Length Substring With Two Occurrences 

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            map<char,int>m;
            for(int j=i;j<s.length();j++)
            {
                m[s[j]]++;
                if(m[s[j]]>2)
                    break;
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};

--------------------------------------------------------------------------------------------------------------

O(N)
Length of Longest Subarray With at Most K Frequency 

Sliding window
create a map and for every integer stores its occuring indexes in a vector ( avoid n^2 complexity of again finding the index for finding the second occurance )


class Solution {
public:


    int maxSubarrayLength(vector<int>& nums, int k) {
           map<int,vector<int>>m;
           int ans=0;
           for(int i=0,j=0;i<nums.size();i++) // i moves ahead, j only moves when >k means then only we shrik the window.
           {
                m[nums[i]].push_back(i);
                
                if(m[nums[i]].size()>k)
                {
                    if(m[nums[i]].front()>=j)
                    {
                        j=m[nums[i]].front()+1;
                    }
                    m[nums[i]].erase(m[nums[i]].begin());
                }     
                ans=max(ans,i-j+1); // shrinking removes the other elements too because they might get in betweeen the >k occurance of the element.
           }
           return ans;
    }
};

*/