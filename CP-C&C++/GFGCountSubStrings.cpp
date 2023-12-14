


//APPROACH 1 (TIME LIMIT EXCEEDED)
// class Solution{
// public:
	
// 	int countSubstr (string S)
// 	{
// 	    // your code here
// 	    int c=0;
// 	    int size=S.length();
// 	    for(int i=0;i<size-1;i++)
// 	    {
// 	        if(S[i]=='1')
// 	        {
// 	          for(int j=i+1;j<size;j++)
// 	            {
// 	                if(S[j]=='1')
// 	                {
// 	                    c++;
// 	                }
// 	            }  
// 	        }
	        
// 	    }
// 	    return c;
// 	}
// };


//APPROACH 2  The expression  (c*(c-1))/2  calculates the number of ways to choose 2 items from a set of 'c' items without considering the order. This calculation is equivalent to C(c,2), which represents the number of combinations of 'c' things taken 2 at a time.
//UNIQUE AND ORDER DOES'NT MATTER
// if you have 'c' occurrences of '1' in the string, this formula tells you how many unique pairs of '1's can be formed from those occurrences, without considering the sequence or arrangement of those pairs within the string.

// class Solution{
// public:
	
// 	int countSubstr (string S)
// 	{
// 	    // your code here
// 	    int c=0;
// 	    int size=S.length();
// 	    for(int i=0;i<size;i++)
// 	    {
// 	        if(S[i]=='1')
// 	        {
// 	            c++; 
// 	        }
	        
// 	    }
// 	    return (c*(c-1))/2;
// 	}
// };