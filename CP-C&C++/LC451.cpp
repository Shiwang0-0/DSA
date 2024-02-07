
/*
using priority queue

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        priority_queue<pair<int,char>>pq; // consider taking int,char and not char,int.
        // reason described below

        // storing characters count in a unordered map
        for(char c:s)
            m[c]++;
        
        // making a max heap out of it (on the basis of frequency of characters)
        // if priority queue was <char,int>
        //it will prioritize the elements based on the first value (the character) 
        //and then based on the second value (the integer). 
        //This means, for example, if two pairs have the same character,
        // the one with the higher integer value will have a higher priority.

        for(auto i:m)
            pq.push(make_pair(i.second,i.first));

        s="";
        while(!pq.empty())
        {
            int len=pq.top().first;
            for(int i=0;i<len;i++)
            {
                s.push_back(pq.top().second);
            }
            pq.pop();
        }
    return s;
    }
};

*/