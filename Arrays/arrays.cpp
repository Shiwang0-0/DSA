// YOU ARE GIUVEN AN ARRAY OF SIZE N CONTAINING EACH NUMBER BTW 1 AND N-1 AT LEAST ONCE.THERE IS A SINGLE INT VALUE THAT IS PRESENT INT THE ARRAY TWICE.FIND THE DUPLICATE INT VALUE PRESENT IN THE ARRAY.

// #include<iostream>
// using namespace std;

// int main()
// {
//     int arr[100],size,i,j;
//     cin>>size;
//     for ( i = 0; i < size; i++)
//     {
//         cin>>arr[i];
//     }
//     int ans=0;
//     for (int i = 0; i < size; i++)
//     {
//         ans=ans^arr[i];
//     }
//     for (int i = 0; i < size; i++)
//     {
//         ans=ans^i;
//     }

//     cout<<ans;

//     return 0;
// }





//INTERSECTION OF TWO ARRAYS: CODING NINJAS(GOOD QUESTION, 1 IMPORTANT CASE BLUNDER),,LECTURE 10,QUESTION 4 AROUND 40MINS.
// #include<iostream>
// #include<climits>
// using namespace std;

// int main()
// {
//     int n,m,arr[100],brr[100],count=0;
//     cin>>n>>m;
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         cin>>brr[i];
//     }
    
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {

//             if (arr[i]==brr[j])
//             {
//                 count++;
//                 cout<<brr[j];
//                 brr[j]= INT_MIN;
//                 break;
//             }
            
//         }  
//     }
//     if (count==0)
//     {
//         cout<<-1;
//     }
   
//     return 0;
// }



//INSERTING and DELETING elements at the left most index of the array.

#include<iostream>
using namespace std;

void func_enter_array(int arr[],int m);
void func_delete_array(int arr[], int m);
int main()
{
    int m,arr[100];
    cout<<"enter size of array";
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>arr[i];
    }
    
    func_enter_array(arr,m);
    func_delete_array(arr,m);
    return 0;
}

void func_enter_array(int arr[],int m)
{
    int i;
    for(i=m-1;i>=0;i--)
    {
        arr[i+m]=arr[i];
    }
    cout<<"enter elements"<<endl;
    for(i=0;i<m;i++)
    {
        cin>>arr[m-1-i];
    }
    cout<<"the final array is :"<<endl;
    for ( i = 0; i < (2*m); i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
}

void func_delete_array(int arr[],int m)
{
    for (int i = 0; i < m; i++)
    {
        arr[i]=arr[m+i];
    }
    cout<<"array after deleting the elements"<<endl;
    for (int i = 0; i < m; i++)
    {
        cout<<arr[i];
    }
    
}




//*****************ROTATED ARRAY METHOD 1******************
// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     int arr[100],temp[100];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         temp[i]=arr[i];
//     }
//     int k,l;
//     cin>>k;
//     for (int i = 0; i < n; i++)
//     {
//         if ((i+k)<n-1)
//         {
//             temp[i+k]=arr[i];
//         }
        
//         else
//         {
//             l=(i+k)%n;
//             temp[l]=arr[i];
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout<<temp[i];
//     }
//     return 0;
// }

//*****************ROTATED ARRAY METHOD 2******************
// #include <stdio.h>
// void rotate(int[], int, int);
// int main() {
//   int n;
//   printf("ENTER NO. OF ELEMENTS");
//   scanf("%d", &n);
//   int arr[n], i = 0, r;
//   printf("ENTER ELEMENTS");
//   for (i; i < n; i++) {
//     scanf("%d", &arr[i]);
//   }
//   printf("\nELEMENTS ARE:");
//   for (i = 0; i < n; i++) {
//     printf("%d\t", arr[i]);
//   }
//   printf("ENTER NO. OF TIMES TO ROTATE ARRAY");
//   scanf("%d", &r);
//   rotate(arr, r, n);
//   printf("ROTATED ELEMENTS ARE:");
//   for (i = 0; i < n; i++) {
//     printf(" %d\t", arr[i]);
//   }
// return 0;
// }
// void rotate(int arr[], int r, int n) {
//   int temp = 0;
//   if (r < n) {

//   } else {
//     r = r % n;
//   }
//   for (int i = 0; i < r; i++) {
//     temp = arr[0];
//     for (int j = 0; j < n; j++) {
//       arr[j] = arr[j + 1];
//     }
//     arr[n - 1] = temp;
//   }
// }


//*****************ROTATED ARRAY METHOD 3******************
// #include <stdio.h>
// void rotate(int[], int, int);
// int main() {
//   int n;
//   printf("ENTER NO. OF ELEMENTS");
//   scanf("%d", &n);
//   int arr[n], i = 0, r;
//   printf("ENTER ELEMENTS");
//   for (i; i < n; i++) {
//     scanf("%d", &arr[i]);
//   }
//   printf("\nELEMENTS ARE:");
//   for (i = 0; i < n; i++) {
//     printf("%d\t", arr[i]);
//   }
//   printf("ENTER NO. OF TIMES TO ROTATE ARRAY");
//   scanf("%d", &r);
//   rotate(arr, r, n);
//   printf("ROTATED ELEMENTS ARE:");
//   for (i = 0; i < n; i++) {
//     printf(" %d\t", arr[i]);
//   }
//   return 0;
// }
// void rotate(int arr[], int r, int n) {
//   int temp = 0;
//   int temp2[100];
//   if (r > n) {
//     r = r % n;
//   } 
//   for (int i = 0; i < r; i++) {
//         temp2[i] = arr[n - r + i];
//     }

//     for (int i = n - 1; i >= r; i--) {
//         arr[i] = arr[i - r];
//     }

//     for (int i = 0; i < r; i++) {
//         arr[i] = temp2[i];
//     }
  
// }






