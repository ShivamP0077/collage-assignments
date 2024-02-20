#include<iostream>
#include<vector>
using namespace std;

// Time Complexity:
// Best Case: O(n) (when the array is already sorted)
// Worst Case: O(n^2) (when the array is reverse sorted)
// Space Complexity: O(1)
// Stable: Yes
// In-Place: Yes
// Adaptive: Yes (efficient for partially sorted data)

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int current = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}


int main(void) {
    vector<int> arr{11, 25, 12, 22, 64};

    insertionSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}