//Peak Index in the Mountain Array(LC)

#include <iostream>
using namespace std;

// Function to find the peak element
int Peak(int arr[], int s, int e) {
    // Base case: when start and end converge
    if (s == e) {
        return s; // Return the index of the peak element
    }

    int mid = s + (e - s) / 2;

    // Check if mid element is less than the next element
    if (arr[mid] < arr[mid + 1]) {
        // If yes, the peak lies in the right half
        return Peak(arr, mid + 1, e);
    } else {
        // Otherwise, the peak lies in the left half
        return Peak(arr, s, mid);
    }
}

int main() {
    // Input array
    int arr[] = {3, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]); // Size of the array

    // Find the peak element
    int peakIndex = Peak(arr, 0, n - 1);

    // Output the peak element
    cout << "Peak element is at index " << peakIndex << " with value " << arr[peakIndex] << endl;

    return 0;
}
