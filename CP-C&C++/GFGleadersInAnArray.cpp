//Leader in an array is the element for which all elements to its right are less than the itself.
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector <int> ans;
        
        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=i+1;j<n;j++)
            {
                if(a[i]<a[j])
                {
                    c++;
                }
                if(c>0)
                break;
            }
            if(c==0)
            ans.push_back(a[i]);
        }
    return ans;
    }
};

