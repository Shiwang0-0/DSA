
// T.C : O(N^2)
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>>v;
        int maxDeadLine=0;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i].profit,arr[i].dead});
            maxDeadLine=max(maxDeadLine,arr[i].dead);
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        
        
        vector<int>seq(maxDeadLine+1,0);
        for (int i = 0; i < v.size(); i++) {
        // Schedule each job at its earliest possible deadline
        for (int j = v[i].second; j >= 1; j--) {
            if (seq[j] == 0) {
                seq[j] = v[i].first;
                break;
            }
        }
        }
        
        int jobsDone=0,profit=0;
        for(int i=0;i<=maxDeadLine;i++)
        {
            if(seq[i]!=0)
            {
                jobsDone++;
                profit+=seq[i];
            }
        }
        return {jobsDone,profit};
    } 
};

// -----------------------------------------------------------------------------------------------------------

// PRIORITY QUEUE
// T.C : O(NlogN)

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<pair<int,int>>v;
        int maxDeadLine=0;
        priority_queue<int>pq;
        int jobsDone=0,profit=0;
        for(int i=0;i<n;i++)
        {
            maxDeadLine=max(maxDeadLine,arr[i].dead);
        }
        
        vector<vector<int>>seq(maxDeadLine+1);
        for(int i=0;i<n;i++)
        {
            seq[arr[i].dead].push_back(arr[i].profit); // for same deadline
            // store all possible profits
        }
        for(int i=maxDeadLine;i>0;i--) // start with maxDeadLine first
        {
            for(int j=0;j<seq[i].size();j++)
            {
                pq.push(seq[i][j]); // stores the maximum profit for that specific deadline at top.
            }
            if(!pq.empty())
            {
                jobsDone++;
                profit+=pq.top();
                pq.pop();
            }
        }

        return {jobsDone,profit};
    } 
};