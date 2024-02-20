#include<iostream>
#include<sys/time.h>
#include<vector>
using namespace std;

void makeAsc(int num, vector<int> &asc)
{
    for (int i = 0; i < num; i++)
    {
        asc[i] = i;
    }
}

void makeDesc(int num, vector<int> &desc)
{
    for (int i = 0; i < num; i++)
    {
        desc[i] = num - i;
    }
}

void makeRand(int num, int mini, int maxi, vector<int> &ran)
{
    for (int i = 0; i < num; i++)
    {
        ran[i] = (rand() % (maxi - mini + 1)) + mini;
    }
}

void marge(vector<int> &arr,int s1,int e1,int s2,int e2)
{
    int l1 = e1 - s1 +1;
    int l2 = e2 - s2+1;

    vector<int> temp1(l1);
    vector<int> temp2(l2);

    for(int i = 0; i<l1; i++)
    {
        temp1[i] = arr[s1 + i];
    }

    for(int i = 0; i<l2; i++)
    {
        temp2[i] = arr[s2 + i];
    }

    int i = 0, j = 0;
    int k = s1;

    while(i < l1 && j < l2)
    {
        if(temp1[i] < temp2[j])
        {
            arr[k] = temp1[i];
            i++;
        }
        else
        {
            arr[k] = temp2[j];
            j++;
        }

        k++;
    }

    while(i < l1)
    {
        arr[k++] = temp1[i++];
    }

    while(j < l2)
    {
        arr[k++] = temp2[j++];
    }

}


void margeSort(vector<int> &arr,int start,int end)
{
   if(start >= end)
    return;
  
   int mid = (start + end)/2;
 
    margeSort(arr,start,mid);

    margeSort(arr,mid+1,end);

    marge(arr,start,mid,mid+1,end);
}

int main(void)
{
    int num = 1000;

    vector<int> asc(num);
    vector<int> desc(num);
    vector<int> ran(num);


    timeval t1,t2;

    makeAsc(num,asc);
    gettimeofday(&t1,NULL);
    margeSort(asc,0,num-1);
    gettimeofday(&t2,NULL);

    cout<<"--------------------------------Best Case--------------------------------------"<<endl;

    cout<<"time difference in microsec :"<<t2.tv_usec - t1.tv_usec<<endl;

    makeRand(num,0,num,ran);
    gettimeofday(&t1,NULL);
    margeSort(ran,0,num-1);
    gettimeofday(&t2,NULL);

    cout<<"--------------------------------Avg Case--------------------------------------"<<endl;

    cout<<"time difference in microsec :"<<t2.tv_usec - t1.tv_usec<<endl;

    makeDesc(num,desc);
    gettimeofday(&t1,NULL);
    margeSort(desc,0,num-1);
    gettimeofday(&t2,NULL);

    cout<<"--------------------------------worst Case--------------------------------------"<<endl;

    cout<<"time difference in microsec :"<<t2.tv_usec - t1.tv_usec<<endl;
}
