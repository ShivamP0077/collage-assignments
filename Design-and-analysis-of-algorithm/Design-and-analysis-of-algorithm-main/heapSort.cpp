#include<iostream>
#include<sys/time.h>
#include<vector>
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

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(void) {
    int num = 1000;

    vector<int> asc(num);
    vector<int> desc(num);
    vector<int> ran(num);

    timeval t1, t2;

    makeAsc(num, asc);
    gettimeofday(&t1, NULL);
    heapSort(asc, num);
    gettimeofday(&t2, NULL);

    cout << "--------------------------------Best Case--------------------------------------" << endl;
    cout << "time difference in microsec: " << t2.tv_usec - t1.tv_usec << endl;

    makeRand(num, 0, num, ran);
    gettimeofday(&t1, NULL);
    heapSort(ran, num);
    gettimeofday(&t2, NULL);

    cout << "--------------------------------Avg Case--------------------------------------" << endl;
    cout << "time difference in microsec: " << t2.tv_usec - t1.tv_usec << endl;

    makeDesc(num, desc);
    gettimeofday(&t1, NULL);
    heapSort(desc, num);
    gettimeofday(&t2, NULL);

    cout << "--------------------------------Worst Case--------------------------------------" << endl;
    cout << "time difference in microsec: " << t2.tv_usec - t1.tv_usec << endl;
}
