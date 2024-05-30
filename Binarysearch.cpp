#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int up, int key) {
    // Check base case
    if (low > up)
        return -1;// can not find 

    int mid = (up + low) / 2;

    // Check if key is present at mid
    if (arr[mid] == key)
        return mid;

    // If key greater, ignore left half
    if (arr[mid] < key)
        return binarySearch(arr, mid + 1, up, key);

    // If key is smaller, ignore right half
    return binarySearch(arr, low, mid - 1, key);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 51, 60, 73, 83, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 73;
    int result = binarySearch(arr, 0, n - 1 , key);

      if (result == -1) {
        cout << "Element is not in array!";
    } else {
        cout << "Element " << key << " is at index: " << result;
    }
    
    return 0;
}
