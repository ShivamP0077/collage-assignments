#include<iostream>
#include<array>
using namespace std;

// Time Complexity:
// Best Case: O(n log n)
// Worst Case: O(n log n)
// Space Complexity: O(n)
// Stable: Yes
// In-Place: No (requires additional memory)

void marge(int arr[],int s,int e)
{
    int mid = (s+e)/2;
    int l1 = mid - s +1;
    int l2 = e-mid;

    int *f = new int[l1];
    int *r = new int[l2];

    int start = s;
    for (int i = 0; i<l1; i++)
      f[i] = arr[start++];

    start = mid+1;
    for (int i = 0; i<l2; i++)
      r[i] = arr[start++];

      int i1 = 0,i2 = 0;
      start = s;

      while(i1 < l1 && i2 < l2)
      {
        if (f[i1] < r[i2])
        arr[start++] = f[i1++];
        else
           arr[start++] = r[i2++];
      }

      while (i1 < l1)
       arr[start++] = f[i1++];

       while( i2 < l2)
         arr[start++] = r[i2++];

}

void margeSort(int arr[],int s, int e)
{
    if(s >= e)
      return;

     int  mid = (e+s)/2;

     margeSort(arr,s,mid);

     margeSort(arr,mid+1,e);

     marge(arr,s,e);


}

int main(void){

    int arr[] = {11,25,12,22,64};

    margeSort(arr,0,4);



    for (int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<arr[i]<<" ";
    }
}