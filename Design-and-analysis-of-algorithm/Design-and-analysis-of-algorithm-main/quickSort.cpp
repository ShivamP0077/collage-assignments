#include <iostream>
#include <sys/time.h>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void makeAsc(int num, vector<int> &asc) {
    for (int i = 0; i < num; i++) {
        asc[i] = i;
    }
}

void makeDesc(int num, vector<int> &desc) {
    for (int i = 0; i < num; i++) {
        desc[i] = num - i;
    }
}

void makeRand(int num, int mini, int maxi, vector<int> &ran) {
    for (int i = 0; i < num; i++) {
        ran[i] = (rand() % (maxi - mini + 1)) + mini;
    }
}

int findPivot(vector<int> &arr, int start, int end) {
    int key = arr[start];
    int i = start + 1;
    int j = end;

    while (i < j) {
        if (arr[i] < key)
            i++;
        else if (arr[j] > key)
            j--;

    }

    swap(arr[i], arr[start]);

    return i;
}

void quickSort(vector<int> &arr, int start, int end) {
    if (start >= end)
        return;

    int pivot = findPivot(arr, start, end);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int main(void) {
    int num = 500;

    vector<int> asc(num);
    vector<int> desc(num);
    vector<int> ran(num);

    timeval t1, t2;

    makeAsc(num, asc);
    gettimeofday(&t1, NULL);
    quickSort(asc, 0, num - 1);
    gettimeofday(&t2, NULL);

    cout << "--------------------------------Best Case--------------------------------------" << endl;

    cout << "time difference in microsec: " << t2.tv_usec - t1.tv_usec << endl;

    makeRand(num, 0, num, ran);
    gettimeofday(&t1, NULL);
    quickSort(ran, 0, num - 1);
    gettimeofday(&t2, NULL);

    cout << "--------------------------------Avg Case--------------------------------------" << endl;

    cout << "time difference in microsec: " << t2.tv_usec - t1.tv_usec << endl;

    makeDesc(num, desc);
    gettimeofday(&t1, NULL);
    quickSort(desc, 0, num - 1);
    gettimeofday(&t2, NULL);

    cout << "--------------------------------Worst Case--------------------------------------" << endl;

    cout << "time difference in microsec: " << t2.tv_usec - t1.tv_usec << endl;
}
