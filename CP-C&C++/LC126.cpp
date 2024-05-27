class Solution {

public:
    vector<vector<string>>ans;
    void dfs(string &word,map<string,int>&m,vector<string>&seq,string beginWord,int len)
    {
        if(word==beginWord)
        {
            reverse(seq.begin(),seq.end()); // since you need the reverse seq before pushing.
            ans.push_back(seq);
            reverse(seq.begin(),seq.end()); // dont dont need to retain the reversed version since you will be popping back the element from the seq.
            return;
        }
        int steps=m[word];
        for(int i=0;i<len;i++)
            {
                char original=word[i];
                for(int j=0;j<26;j++)
                {
                    word[i]=j+'a';
                    if(m.find(word)!=m.end() && m[word]+1==steps)
                    {
                        seq.push_back(word);
                        dfs(word,m,seq,beginWord,len);
                        seq.pop_back();
                    }
                }
                word[i]=original;
            }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        map<string,int>m;
        m[beginWord]=1;
        st.erase(beginWord);
        q.push(beginWord);
        int len=beginWord.size();
        while(!q.empty())
        {
            string word=q.front();
            q.pop();
            int step=m[word];
            if(word==endWord)
                break;
            for(int i=0;i<len;i++)
            {
                char original=word[i];
                for(int j=0;j<26;j++)
                {
                    word[i]=j+'a';
                    if(st.count(word)>0)
                    {
                        q.push(word);
                        st.erase(word); // remove other wise you will reiterate pm  it.
                        m[word]=step+1;
                    }
                }
                word[i]=original;
            }
        }

        if(m.find(endWord)!=m.end())
        {
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,m,seq,beginWord,len);
        }
        return ans;
    }
};