/*
Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

[ 9 2 7 8
  6 4 3 7
  5 8 1 8
  7 6 9 4 ]

Sample Output
13

Constraints
N <= 20

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <bits/stdc++.h>
using namespace std;

// max N 
int cost[21][21]; // row represents the person, col represents the job a person will do
int dp[21][1<<21]; // for 20 jobs, what and how permuation of people i will choose
                   // so mask of 2^21 is taken to represent that there are this many possible combination to take 20 people, for 20 jobs
                   // jobs * (people)

int func(int i,int mask,int n){
    if(i==n) // reached beyond the last employee
        return 0;
    
    if(dp[i][mask]!=-1)
        return dp[i][mask];

    int ans=INT_MAX;
    for(int j=0;j<n;j++){ // select the jth person for the current ith job

        if(mask&(1<<j)) // if i can take the jth person for this ith job
            ans=min(ans,cost[j][i]+ func(i+1,mask^(1<<j),n) );
            // since you have selected jth person, turn its bit off so you cannot choose it later
    }

    return dp[i][mask]=ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(dp, -1, sizeof(dp));
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> cost[i][j];
    }
    cout<<func(0,(1<<n)-1,n); // 0th job, and mask initially all ones
    // NOTE: because here the mask represents how many jobs are avaialable, we take mask as (2^n)-1
    // meaning if n=4, we have 16-1 ---> 15 ---> ( 1111 ) in bit mask 4 jobs to do

    // if it would have been travelling saleman problem, where the saleman starts from a node, 
    // the mask would have been (2^n)-2
    // meanin gif n=4, we have 16-2 ---> 14 ---> ( 1101 ) in bit mask 3 more nodes to travel
    
return 0;
}