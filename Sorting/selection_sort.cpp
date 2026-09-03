
// LOGIC SELECTION SORT

#include<iostream>
using namespace std;

int main()
{
    int n=0,minelement=0;
    int arr[100];
    cout<<"helo";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++)
   {
       int minelement=i;
       for(int j=i+1;j<n;j++)
       {
           if(arr[minelement]>arr[j])
           {
               minelement=j;
           }
       }
       swap(arr[minelement],arr[i]);
   }

   for (int i = 0; i < n; i++)
   {
    cout<<arr[i];
   }
   
    return 0;
}