class Solution {
public:

    // brute 
    // O(N^2)
    // will give TLE

    string minWindow(string s, string t) {
        int n=s.length(),m=t.length(),miniLen=1e9,sIdx=-1;
        string ans;
        for(int i=0;i<n;i++){
            map<char,int>mpp;
            int count=0;
            for(int k=0;k<m;k++)
            {
                mpp[t[k]]++;
            }
            int j=i;
            for(j=i;j<n;j++)
            {
                if(mpp[s[j]]>0){//first occurance of letter is seen in both s & t.
                // count of the alphabet actually, not the distinct "alphabet".
                    count=count+1;
                }
                mpp[s[j]]--;
                if(count==m){
                    if(j-i+1<miniLen){
                        miniLen=j-i+1;
                        sIdx=i;
                        break;     
                    }      
                }
            }
           if(sIdx!=-1) ans=s.substr(sIdx,miniLen); 
        }
    if(sIdx==-1)
        return "";
    return ans;
    }
};




class Solution {
public:

    // SLIDING WINDOW
    // O(2*N)

    string minWindow(string s, string t) {
        int n=s.length(),m=t.length(),miniLen=1e9,sIdx=-1,r=0,l=0,count=0;
        string ans;
        map<int,int>mpp;
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        while(r<n)
        {
            if(mpp[s[r]]>0){
                count=count+1;
            }
            while(count==m){
                mpp[s[l]]++;
                if(r-l+1<miniLen){
                    miniLen=r-l+1;
                    sIdx=l;
                }  
                if(mpp[s[l]]>0){
                    count=count-1;
                }                 
                l++;    
            }
            mpp[s[r]]--;
            r++;
        }
        if(sIdx==-1)
            return "";
        return s.substr(sIdx,miniLen);
    }
};