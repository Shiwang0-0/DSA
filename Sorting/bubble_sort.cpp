// // Logic
#include <bits/stdc++.h>
void bubbleSort(vector<int> &arr, int n)
{
    int i = 0;
    while (i < n - 1) //tells which round is taken into consideration
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
        i++;
    }
}

// **************more optimised************
// #include <bits/stdc++.h>
// void bubbleSort(vector<int> &arr, int n)
// {
//     int i = 0;

//     while (i < n - 1)  //tells which round is taken into consideration
//     {
//         bool swapped = false;
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//                 swapped = true;
//             }
//         }

//         i++;
//         if (swapped == false)
//             // means already sorted

//             break;
//     }
// }

