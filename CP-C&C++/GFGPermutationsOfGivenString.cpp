
// Permutation of a String

// class Solution
// {
// 	public:
	
// 	    void solve(vector<string>&ans,string S,int i)
// 	    {
// 	        if(i>=S.length())
// 	        {
// 	            ans.push_back(S);
// 	            return;
// 	        }
// 	        for(int j=i;j<S.length();j++)
// 	        {
// 	           // char c=S[j];
// 	            swap(S[i],S[j]);
// 	            solve(ans,S,i+1);
// 	            swap(S[j],S[i]);
// 	        }
// 	    }
	
// 		vector<string>find_permutation(string S)
// 		{
		  
// 		  vector<string> ans;
// 		  solve(ans,S,0);
// 		  sort(ans.begin(),ans.end());
//           ans.erase(unique(ans.begin(),ans.end()),ans.end());
// 		  return ans;
// 		}
// };
