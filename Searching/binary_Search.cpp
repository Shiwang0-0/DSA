#include<iostream>
using namespace std;

int main()
{
    int start=0,end=6,key=80,mid;
    int arr[7]={3,4,8,9,10,43,88};

    //for even
    //end=5
    //int arr[6]={3,4,8,9,10,88};
    
    mid=start+(end-start)/2;
    while (start<=end)
    {
        if (arr[mid]==key)
        {
            cout<<mid;
            return 0;
        }
        else if(arr[mid]<key)
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    cout<<-1;
    return 0;
}







//FIRST AND LAST OCCURENCE OF AN ELEMENT AND NUMBER OF TIMES IT IS BEING REPEATED.
// int firstocc(int start,int end,int arr[8],int key)
// {
//     int m=-1;
//     int mid=start+(end-start)/2;
//     while (start<=end)
//     {
//        if (arr[mid]==key)
//        {
//         m=mid;
//         end=mid-1;
//        }
//        else if(arr[mid]>key)
//        {
//         end=mid-1;
//        }
//        else
//        {
//         start=mid+1;
//        }
//        mid=start+(end-start)/2;
//     }
//     return m;
// }
// int secondocc(int start,int end,int arr[8],int key)
// {
//     int m=-1;
//     int mid=start+(end-start)/2;
//     while (start<=end)
//     {
//        if (arr[mid]==key)
//        {
//         m=mid;
//         start=mid+1;
//        }
//        else if(arr[mid]>key)
//        {
//         end=mid-1;
//        }
//        else
//        {
//         start=mid+1;
//        }
//        mid=start+(end-start)/2;
//     }
//     return m;
// }
// #include<iostream>
// using namespace std;

// int main()
// {
//     int arr[8]={1,1,2,2,2,2,14,16};
//     int start=0,end=7,key=2;
//     int j=firstocc(start,end,arr,key),k=secondocc(start,end,arr,key);
//     cout<<"first occurence is at index " <<j<<endl;
//     cout<<"last occurence is at index " <<k<<endl;
//     cout<<"number of time the key is repeated is :"<<k-j+1;
    
    
    
//     return 0;

// }


//MOUNTAIN ARRAY
// #include<iostream>
// using namespace std;

// int main()
// {
//     int arr[6]={0,2,3,4,8,1};
//     int start=0,end=5,m=-1;
//     int mid=start+(end-start)/2;
//     while (start<end)
//     {
        
        
//         if (arr[mid]<arr[mid+1])
//         {
//             start=mid+1;
//         }
//         else{
//             end=mid;
//         }
//         mid=start+(end-start)/2;
//     }
//     cout<<"the maximum element is at the index :"<<start;
//     return 0;
// }



//PIVOT POINT IN AN ARRAY

// #include<iostream>
// using namespace std;

// int main()
// {
//     //sorted array was {1,4,7,8,10}
//     //afer rotation
//     //rotated array is {8,10,1,4,7}
//     //we can divide it into two monotonic increasing arrays means bianry search can be implemented.
//     int arr[5]={8,10,1,4,7};
//     int start=0;
//     int end=4;
//     int mid=start+(end-start)/2;
//     while (start<end)
//     {
//         if (arr[0]<arr[mid])
//         {
//             start=mid+1;
//         }
//         else
//         {
//             end=mid;
//         }
//         mid=start+(end-start)/2;
        
//     }
//     cout<<"the pivot of the array is at index:" <<start;
//     return 0;
// }



// find the index of an element(SEARCH  ) which was sorted but then rotated
// #include<iostream>
// using namespace std;

// int main()
// {
//     int arr[5]={7,9,1,2,3};
//     int s=0;
//     int e=4;
//     int mid=s+(e-s)/2;
//     int key=3;
//     while (s<e)     
//     {
//         if (arr[0]>key)
//         {
//             s=mid;
//         }
//         else
//         {
//             e=mid-1;
//         }
//         mid=s+(e-s)/2;
//         if (arr[mid]==key)
//         {
//             s=mid;
//             e=mid;
//         }
        
//         else if(arr[mid]>=key)
//         {
//             e=mid-1;
//         }
//         else
//         {
//             s=mid+1;
//         }
//         mid=s+(e-s)/2;
//     }
//     cout<<"the key is at index : "<<s;
//     return 0;
// }



// *********ALTERNATIVE OF find the index of an element(SEARCH  ) which was sorted but then rotated ********

// #include<vector>
// using namespace std;

// int getPivot(vector<int>& arr, int n) {

//     int s = 0;
//     int e = n-1;
//     int mid = s + (e-s)/2;

//     while(s<e) {

//         if(arr[mid] >= arr[0])
//         {
//             s = mid+1;
//         }
//         else{
//             e = mid;
//         }
//         mid = s + (e-s)/2;
//     }
//     return s;
// }

// int binarySearch(vector<int>& arr, int s, int e, int key) {

//     int start = s;
//     int end = e;

//     int mid = start + (end-start)/2;

//     while(start <= end) {

//         if(arr[mid] == key) {
//             return mid;
//         }

//         //go to right wala part
//         if(key > arr[mid]) {
//             start = mid + 1;
//         }
//         else{ //key < arr[mid]
//             end = mid - 1;
//         }

//         mid = start + (end-start)/2;
//     }
    
//     return -1;
// }



// int findPosition(vector<int>& arr, int n, int k)
// {
//     int pivot = getPivot(arr, n);
//     if( k >= arr[pivot] && k <= arr[n-1])
//     {//BS on second line
//         return binarySearch(arr, pivot, n-1, k);
//     }
//     else
//     {//BS on first line
//         return binarySearch(arr, 0, pivot - 1, k);
//     }
    
// }



//*****ANOTHER ALTERNATIVE OF find the index of an element(SEARCH  ) which was sorted but then rotated ****** (ALL THREE PREVIOUS ALTERNATIVE HAVE SAME TIME COMPLEXITY THAT IS O(logn) THIS THIRD ONE CAN AROUND 50% MINIMZE THE SECOND ALTERNATIVE APPORACH)

//HOMEWORK


//????????????????????????????