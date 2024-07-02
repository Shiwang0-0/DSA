// T.C: O(N^2)
// S.C: O(N)

class Solution {

private:
    string compareFunc(string s,string t)
    {
        string ans;
        map<char,int>m,n;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            if(m.find(t[i])!=m.end() && m[t[i]]!=0)
            {
                ans.push_back(t[i]);
                m[t[i]]--;
            }
        }
        return ans;
    }

public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        string common;
        common=words[0];
        for(int i=1;i<words.size();i++)
        {
            common=compareFunc(common,words[i]);
        }
        cout<<common;
        for(int i=0;i<common.length();i++)
        {
            char c=common[i];
            ans.push_back(string(1,c));
            // to get a string from single character
            // string class has a constructor
            // that allows us to specify size of
            // string as first parameter and character
            // to be filled in given size as second
            // parameter.
        }
        return ans;
    }
};


// --------------------------------------------------------------------------------------------------------


// T.C: O(N)
// S.C: O(N)

class Solution {

public:
    vector<string> commonChars(vector<string>& words) {
        string ans;
        for(char c='a'; c<='z';c++) // 26 max
        {
            int miniCounts=INT_MAX;
            for(auto word:words) // 100 max
            {
                int count=0;
                for(auto ch:word) // 100 max
                {
                    if(ch==c)
                        count++;
                }
                miniCounts=min(count,miniCounts);
                if(miniCounts==0) // means word ka koi bhi character c se match ni hua
                    break;

            }
            for(int j=0;j<miniCounts;j++) // 100 max
            {
                ans.push_back(c);
            }
        }
        cout<<ans;
        vector<string>v;
        for(int i=0;i<ans.length();i++)
        {
            char ch=ans[i];
            v.push_back(string(1,ch));
        }
        return v;
    }
};