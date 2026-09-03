
#include<iostream>
using namespace std;
int BS(int arr[],int start,int end,int k)
{
    int index=-1;
    if(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==k)
        {
            return mid;
        }
        
        else if(arr[mid]>k)
        {
            index=BS(arr,start,mid-1,k);
        }
        else
        {
            index=BS(arr,mid+1,end,k);
        }
    return index;  
    }
    return -1;
}
  
int binarysearch(int arr[], int n, int k) {
        
        int start=0;
        int end=n-1;
        return BS(arr,start,end,k);
}

int main()
{
    int arr[100];
    int n,k;
    cout<<"enter size: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"enter element you want to search ";
    cin>>k;
    cout<<"the element is at index "<<binarysearch(arr,n,k);

    return 0;
}