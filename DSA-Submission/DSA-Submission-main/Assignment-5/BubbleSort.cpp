#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n^2) (worst-case and average-case)
// Space Complexity: O(1)
// Best Case: O(n) (when the array is already sorted)
// Worst Case: O(n^2) (when the array is reverse sorted)
// Stable: Yes
// In-Place: Yes

void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        bool swap = false;

        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;
            }
        }

        if (swap == false)
            break;
    }
}

int main(void) {
   vector<int> arr{11, 25, 12, 22, 64};

    bubbleSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}