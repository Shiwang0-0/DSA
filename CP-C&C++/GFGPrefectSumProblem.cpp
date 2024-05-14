
// Easy problem, but
// Look at n==0 condition.


// HINT:
// Zero is also included as element in the array,
// Zero may also be the first element in an array of size 0 and size n too.

/*

class Solution {
    const int MOD = 1000000007;

private:
    int funcDP(int arr[], vector<vector<int>>& dp, int n, int target) {
        if(n==0){  // why this ? 
        // to account numbers when we encounter 0, 0 is also a part of array.
            if(target==0 && arr[0]==0) return 2;
            if(target==0 || target==arr[0]) return 1;
            return 0;
        }

        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        int inclu = 0;
        if (target >= arr[n]) {
            inclu = funcDP(arr, dp, n - 1, target - arr[n])% MOD;
        }

        int dont = funcDP(arr, dp, n - 1, target)% MOD;

        // Store result in dp array
        dp[n][target] = (inclu + dont) % MOD;

        return dp[n][target];
    }

public:
    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return funcDP(arr, dp, n - 1, sum);
    }
};


*/