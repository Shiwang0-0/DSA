



// APPROACH 1
// TIME LIMIT EXCEEDED  T.C: O(N^2)

// long long int inversionCount(long long arr[], long long N)
//     {
//         long long int c=0;
//         for(int i=0;i<N-1;i++)
//         {
//             for(int j=i+1;j<N;j++)
//             {
//                 if(arr[i]>arr[j])
//                     c++;
//             }
//         }
//         return c;
//     }


// APPROACH 2 (Using Merge Sort)
// T.C: O(NlogN)

// class Solution{
//   public:
//     long long int count=0;
    
//     void mergeSort(long long int arr[], long long int s, long long int mid, long long int e)
//     {
//         long long int len1=mid-s+1;
//         long long int len2=e-mid;
    
//         long long int* ptr1= (long long int*)malloc(sizeof(long long int*)*len1);
//         long long int* ptr2= (long long int*)malloc(sizeof(long long int*)*len2);
        
//         long long int index=s;
        
//         for(int i=0;i<len1;i++)
//         {
//             *(ptr1+i)=arr[index++];
//         }
//         index=mid+1;
//         for(int j=0;j<len2;j++)
//         {
//             *(ptr2+j)=arr[index++];
//         }
        
//         long long int k=s;
//         long long int i=0,j=0;
//         while(i<len1 && j<len2)
//         {
//             if( *(ptr1+i)  > *(ptr2+j))
//             {
//                 arr[k++]=*(ptr2+j);
//                 count=count+(len1-i);
//                 j++;
//             }
//             else
//             {
//                 arr[k++]=*(ptr1+i);
//                 i++;
//             }
//         }
        
//         while(i<len1)
//         {
//             arr[k++]=*(ptr1+i);
//             i++;
//         }
//         while(j<len2)
//         {
//             arr[k++]=*(ptr2+j);
//             j++;
//         }
       
//     }
    
//     void merge(long long int arr[], long long int s, long long int e)
//     {
//         if(s>=e)
//             return;
            
//         long long int mid=s+(e-s)/2;
            
//         merge(arr,s,mid);
//         merge(arr,mid+1,e);
        
//         mergeSort(arr,s,mid,e);
//     }
    
//     long long int inversionCount(long long arr[], long long N)
//     {
//         merge(arr,0,N-1); 
//         return count;
//     }

// };
