class Solution{
public:
    vector<int> leftSmaller(int n, int arr[]){
        // code here
        stack<int>s;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int ele=arr[i];
            while(!s.empty() && ele<=s.top()){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=s.top();
            }
            s.push(ele);
        }
        return ans;
    }
};