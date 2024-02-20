#include<iostream>
#include<array>
using namespace std;

// space O(n)
// beast O(N log n)
// worst O(n * n)
// stable sort
// use linklist sorting , inversion sorting, large deta sort
// in place sorting

int getPivot(int arr[],int s,int e)
{
    int count = s;
    int pivot = arr[s];
    for(int i = s+1; i <= e; i++)
    {
        if (pivot > arr[i])
        count++;
    }

    swap(arr[s],arr[count]);

    int i1 = s;
    int i2 = count+1;

    while(i1 <= count-1 && i2 <= e)
    {

        while(i1 <= count-1)
        {
            if (arr[i1] < pivot)
               i1++;
        }

        while(i2 <= e)
        {
            if(arr[i2] > pivot)
              i2++;
        }
        if(i1 <= count-1 && i2 <= e)
          swap(arr[i1],arr[i2]);
    }

    return count;
}

void quickSort(int arr[],int s, int e)
{
    if (s >= e)
      return ;

    int pivot = getPivot(arr,s,e);

    quickSort(arr,s,pivot-1);

    quickSort(arr,pivot+1,e);


}

int main(void){

    int arr[] = {11,25,12,22,64};

    quickSort(arr,0,4);





    for (int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout<<arr[i]<<" ";
    }
}