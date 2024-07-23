class Solution {

private:
    int prevSmallerElement(vector<int>&arr,int i){
        int start=i;
        int ele=arr[i];
        while(i>0){
            if(ele>=arr[i-1]) // use >= in one of the function otherwise,
                            // [4,4]==> will produce min(4,4) two times
                break;
            i--;
        }
        return start-i+1;
    }

    int nextSmallerElement(vector<int>&arr,int i){
        int start=i,n=arr.size();
        int ele=arr[i];
        while(i<n-1){
            if(ele>arr[i+1])
                break;
            i++;
        }
        return i-start+1;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {

        int MOD=1000000007;
        int n=arr.size(),total=0;
        for(int i=0;i<n;i++){
            int preSmall=prevSmallerElement(arr,i);
            int nextSmall=nextSmallerElement(arr,i);
            long long totalCombinations=(preSmall*nextSmall)%MOD;
            
            long long valueOfCurrentEle=((totalCombinations%MOD)*arr[i])%MOD;

            total=(total+valueOfCurrentEle)%MOD;
        }
        return total%MOD;
    }
};


// -------------------------------------------------------------------------

// improvement: insted of running the helper functions every tme, try using previous smaller and next smaller conecpt from STACK, and store them in stacks.


class Solution {

private:
    vector<int> prevSmallerElement(vector<int>&arr){
        int n=arr.size();
        stack<int>s;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int ele=arr[i];
            while(!s.empty() && ele<=arr[s.top()]){
                s.pop();
            }
            if(s.empty()){ // when i=0, and some other cases.
                ans[i]=-1;
            }
            else{
                ans[i]=s.top();
            }
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int>&arr){
        int n=arr.size();
        stack<int>s;
	    vector<int>ans(n);
	    for(int i=n-1;i>=0;i--){
	        int ele=arr[i];
	        
	        while(!s.empty() && ele<arr[s.top()]){  // use >= in one of the function otherwise,
                                            // [4,4]==> will produce min(4,4) two times
	            s.pop();
	        }
	        if(s.empty()){ // means last index 
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
    int sumSubarrayMins(vector<int>& arr) {

        int MOD=1000000007;
        int n=arr.size(),total=0;

        vector<int> preSmall=prevSmallerElement(arr);
        vector<int> nextSmall=nextSmallerElement(arr);

        for(int i=0;i<n;i++){

            int prevSmallestCount=i-preSmall[i];  // for i=0 , (0-(-1)) gives 1 mening include the 0th index ele only.
            int nextSmallestCount=nextSmall[i]-i;

            long long totalCombinations=(nextSmallestCount*prevSmallestCount)%MOD;
            
            long long valueOfCurrentEle=((totalCombinations%MOD)*arr[i])%MOD;

            total=(total+valueOfCurrentEle)%MOD;
        }
        return total%MOD;
    }
};
