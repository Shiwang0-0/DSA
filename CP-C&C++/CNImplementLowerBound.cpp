/*
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0,high=arr.size(),mid=0;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(arr[mid]<x)
			low=mid+1;
		else
			high=mid-1;
	}
	if(high>=arr[arr.size()-1])
		return arr.size();
	return low;
}
*/