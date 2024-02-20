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



void inserctionSort(vector<int> &arr,int n)
{
    for(int i = 1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = key;
    }
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
    inserctionSort(asc,num);
    gettimeofday(&t2,NULL);

    cout<<"--------------------------------Best Case--------------------------------------"<<endl;

    cout<<"time difference in microsec :"<<t2.tv_usec - t1.tv_usec<<endl;

    makeRand(num,0,num,ran);
    gettimeofday(&t1,NULL);
    inserctionSort(ran,num);
    gettimeofday(&t2,NULL);

    cout<<"--------------------------------Avg Case--------------------------------------"<<endl;

    cout<<"time difference in microsec :"<<t2.tv_usec - t1.tv_usec<<endl;

    makeDesc(num,desc);
    gettimeofday(&t1,NULL);
    inserctionSort(desc,num);
    gettimeofday(&t2,NULL);

    cout<<"--------------------------------worst Case--------------------------------------"<<endl;

    cout<<"time difference in microsec :"<<t2.tv_usec - t1.tv_usec<<endl;
}
