class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>lastSeen(256,-1);
        int r=0,l=0,maxLen=0,len=0,n=s.length();
        while(r<n)
        {
            char ch=s[r];
            if(lastSeen[ch]!=-1 && lastSeen[ch]>=l)  // i have seen the element before
            // make sure that element position where you saw is within the current window.
            {
                l=lastSeen[ch]+1;  // move it to one ahead, so that, that element is excluded from the window.
            }

            len=r-l+1; // recompute the new length ( if changed )
            maxLen=max(len,maxLen);
            lastSeen[ch]=r;
            r++;
        }
        return maxLen;
    }
};