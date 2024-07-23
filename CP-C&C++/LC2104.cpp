#define ll long long
class Solution {

private:
    vector<int> prevSmallerElement(vector<int>&nums,int n){
        stack<int>s;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int ele=nums[i];
            while(!s.empty() && ele<nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int>&nums,int n){
        stack<int>s;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int ele=nums[i];

            while(!s.empty() && ele<=nums[s.top()]){
                s.pop();
            }

            if(s.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }

    vector<int> prevGreaterElement(vector<int>&nums,int n){
        vector<int>ans(n);
        stack<int>s;
        for(int i=0;i<n;i++){
             int ele=nums[i];

            while(!s.empty() && ele>=nums[s.top()]){
                s.pop();
            }

            if(s.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }


    vector<int> nextGreaterElement(vector<int>&nums,int n){
        vector<int>ans(n);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            int ele=nums[i];

            while(!s.empty() && ele>nums[s.top()]){
                s.pop();
            }

            if(s.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }

public:
    ll subArrayRanges(vector<int>& nums) {
        // the problem actually boils down to
        // submation(sum of subarray maximums ) - submation ( sum of subarrays min)
        int n=nums.size();

        vector<int> preSmall=prevSmallerElement(nums,n);
        vector<int> nextSmall=nextSmallerElement(nums,n);

        vector<int> preGreater=prevGreaterElement(nums,n);
        vector<int> nextGreater=nextGreaterElement(nums,n);

        ll submationSubarrayMinimum=0,submationSubarrayMaximum=0;

        for(int i=0;i<n;i++){

            int countForPresmaller=i-preSmall[i];
            int countFornextsmaller=nextSmall[i]-i;

            ll totalcombinations=countForPresmaller*countFornextsmaller;

            submationSubarrayMinimum+=(totalcombinations*nums[i]);
        }

        for(int i=0;i<n;i++){

            int countForPreGreater=i-preGreater[i];
            ll countFornextGreater=nextGreater[i]-i;

            ll totalcombinations=countForPreGreater*countFornextGreater;

            submationSubarrayMaximum+=(totalcombinations*nums[i]);
        }

    return submationSubarrayMaximum-submationSubarrayMinimum;
    }
};