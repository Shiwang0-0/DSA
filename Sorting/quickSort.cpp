
	The function is called with the parameters:
	quickSort(input, 0, size - 1);


int partitionArray(int input[], int s, int e) {
	int pivot=input[s];
	int i=s,j=e;

	while(i<j)
	{
		while(input[i]<=pivot && i<e)
			i++;

		while(input[j]>pivot && j>s)
			j--;

		if(i<j)
		{
			swap(input[i],input[j]);
		}
	}
	swap(input[j],input[s]);
	return j;
}

void quickSort(int input[], int start, int end) {
	if(start>=end)
		return;
	
	int p=partitionArray(input, start, end);
	quickSort(input, start, p-1);
	quickSort(input, p+1,end);
}


*/