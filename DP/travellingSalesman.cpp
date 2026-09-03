/*

Given a list of cities numbered from 0 to N-1 and a matrix 'DISTANCE' consisting of 'N' rows and 'N' columns denoting the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the starting city?

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 5
2 <= N <= 16
0 <= DISTANCE[i][j] <= 10^9

Time Limit: 1 sec
Sample Input 1 :
2
4
0 20 42 25
20 0 30 34
42 30 0 10
25 34 10 0
3
0 3 2
3 0 1
2 1 0
Sample Output 1 :
85
6
Explanation of Sample output 1:
For the first test case, 
The shortest possible route is 0 -> 1 -> 2 -> 3 -> 0 = 20 + 30 + 10 + 25 = 85. 

For the second test case,
The shortest possible route is 0 -> 1 -> 2 -> 0 = 3 + 1 + 2 = 6.
Sample Input 2:
2
1
5
2
0 2
2 0
Sample output 2:
5
4

*/

#include <bits/stdc++.h> 

int n;

vector<vector<int>>dp;

int func(vector<vector<int>>&distance,int i,int mask){
	// i denotes the current node salesman is on

	if(mask==0) // no more further nodes to reach
		return distance[i][0]; // reach back to start point: cost[from][to];

	if(dp[i][mask]!=-1)
		return dp[i][mask];

	int cost=INT_MAX;
	for(int j=0;j<n;j++){ // to which node the salesman can go now
		if(mask&(1<<j)){ // if city is not visited yet
			cost=min(cost,distance[i][j]+func(distance,j,(mask^(1<<j))));
			// mark the just visited city as 0 in bit mask, so you dont travel it again
		}
	}
	return dp[i][mask]=cost;
}

int shortestRoute(vector<vector<int>> &distance)
{
	// Write your code here.
	n=distance.size();
	dp.assign(n,vector<int>(1<<n,-1));
	
	int mask=(1<<n)-2; // since there are n cities, there will be 2^n permutations
	

	// for n jobs questions 
	// NOTE: because here the mask represents how many jobs are avaialable, we take mask as (2^n)-1
    // meaning if n=4, we have 16-1 ---> 15 ---> ( 1111 ) in bit mask 4 jobs to do

    // if it would have been travelling saleman problem, where the saleman starts from a node, 
    // the mask would have been (2^n)-2
    // meanin gif n=4, we have 16-2 ---> 14 ---> ( 1101 ) in bit mask 3 more nodes to travel
	return func(distance,0,mask); // start the journey from 0 node
	// since all are connected, the other start points, will lead to permutations only
}
