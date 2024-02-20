#include <iostream>
#include <vector>
using namespace std;

// Time Complexity:
// Best Case: O(n^2)
// Worst Case: O(n^2)
// Space Complexity: O(1)
// Stable: No (unless implemented with care)
// In-Place: Yes

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main(void) {
    vector<int> arr{11, 25, 12, 22, 64};

    selectionSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}