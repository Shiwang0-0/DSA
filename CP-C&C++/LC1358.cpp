// INTUTIVE SLIDING WINDOW 

class Solution {
public:
    int numberOfSubstrings(string s) {
        // instead of treating 0th index as start point of the substrings, treat it as the end point,
        // same with 1th index, treat 1th index as the ending point of substring which were are the left part of the string s.
        int n=s.length(),i=0,count=0;
        vector<int>prev(3,-1); // stores prev seen indexes of a,b,c.
        while(i<n){
            prev[s[i]-'a']=i;
            if(prev[0]!=-1 && prev[1]!=-1 && prev[2]!=-1) // every character is found atleast once
                count=count+min(prev[0],min(prev[1],prev[2]))+1;  // +1 for logic of counting.
                // abc where a is at 0th index creates 1 substring, since min(0,1,2) is 0, and abc is a valid substring i have to do +1.
                i++;
        }
        return count;
    }
};




// for exact k, k = (atmost K) - (atmost K-1)

class Solution {

private:
    int func(string s,int k)
    {
        int n=s.length(),l=0,r=0,count=0;
        map<int,int>m;
        while(r<n)
        {
            m[s[r]]++;
            while(m.size()>k)
            {
                m[s[l]]--;
                if(m[s[l]]==0)
                    m.erase(s[l]);
                l++;
            }
            count=count+(r-l+1);
            r++;
        }
        return count;
    }

public:
    int numberOfSubstrings(string s) {
        // no. of substrings where <condition>

        // no of substrings where there are k distinct elements, k is 3 here.
        // is same as 
        // no of all substrings where there are <= k distinct elements minus
        // the number of substrings where there are  <= k-1 distinct elements

        // k = (atmost K) - (atmost K-1)

        int k=3;
        return func(s,k)-func(s,k-1);
    }
};


