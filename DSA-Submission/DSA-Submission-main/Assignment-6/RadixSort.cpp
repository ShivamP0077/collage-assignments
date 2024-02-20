#include<iostream>
#include<array>
using namespace std;

// space O(n)
// beast O(N log n)
// worst O(n log n)
// stable sort
// use linklist sorting , inversion sorting, large deta sort
// in place sorting


void countingSort(int arr[],int s, int e, int p)
{


  int temp1[10] = {0};
  int temp2[10] = {0};
  int temp3[e-s+1] = {0};

  for (int i = s; i <= e; i++)
  {
     temp1[(arr[i]/p)%10]++;
  }
   int sum = 0;
  for (int i = 0; i < 10; i++)
  {
     sum = sum + temp1[i];
     temp2[i] = sum;

  }

  for (int i = e; i >= s; i--)
  {
    temp2[(arr[i]/p)%10]--;
     temp3[temp2[(arr[i]/p)%10]] = arr[i];
  }

 for (int i = s; i <= e; i++)
 {
    arr[i] = temp3[i-s];
 }


}

 void radixSort(int arr[], int s ,int e)
 {
    int max =arr[0];
    for (int i = 1; i <= e; i++)
    {
        if (max < arr[i])
          max = arr[i];
    }

    for (int p = 1; max/p > 0; p= p*10)
    {
        countingSort(arr,s,e,p);
    }
 }




int main(void){

    int arr[] = {5,4,3,2,1};

    radixSort(arr,0,4);



    for (int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}