#include<iostream>
#include<array>
using namespace std;

// Time Complexity: O(n + k) where n is the number of elements in the input array and k is the range of input.
// Space Complexity: O(n + k)
// Best Case: O(n + k)
// Worst Case: O(n + k)
// Stable: Yes
// In-Place: No (requires additional space proportional to the range of input)


void countingSort(int arr[],int s, int e)
{
    int max =arr[0];
    for (int i = 1; i <= e; i++)
    {
        if (max < arr[i])
          max = arr[i];
    }

  int *temp1 = new int[max];
  int *temp2 = new int[max];
  int *temp3 = new int[e+1];

  for (int i = 0; i <= e; i++)
  {
     temp1[arr[i]]++;
  }
   int sum = 0;
  for (int i = 0; i <= max; i++)
  {
     sum = sum + temp1[i];
     temp2[i] = sum;

  }

  for (int i = e; i >= 0; i--)
  {
    temp2[arr[i]]--;
     temp3[temp2[arr[i]]] = arr[i];
  }

 for (int i = 0; i <= e; i++)
 {
    arr[i] = temp3[i];
 }


}

int main(void){

    int arr[] = {5,4,3,2,1};

    countingSort(arr,0,4);



    for (int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<arr[i]<<" ";
    }
}