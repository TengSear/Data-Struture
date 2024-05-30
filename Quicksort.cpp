#include <iostream>
using namespace std;

int partition(int arr[], int leftIndex, int rightIndex)
    {
      // Variable initialization
        int i = leftIndex;
        int j = rightIndex;
        int pivotValue = arr[leftIndex];// choose the pivot as the left element

        while(i < j){
            while(arr[i] <= pivotValue){ // find to the right but possible greater the right element
                i++;
            }
            while(arr[j] > pivotValue && i < j){ // find to the left but possible greater the left element
                j--;
            }
            if(i < j){ 
              // Swap array
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        //Swap pivot into it correct position 
        int temp = arr[i - 1];
        arr[i - 1] = arr[leftIndex];
        arr[leftIndex] = temp;

        return i - 1;// return the index of the pivot after partitioning 
    }

void quickSort(int arr[], int left, int right)
   {    
      if (left < right)
      {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1); // sort the left 
        quickSort(arr, pivot + 1, right); // sort the right 
      }
   }

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter an array size: ";
    cin >> n;

    int originalArray[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> originalArray[i];
    }

    cout << "Original array : ";
    printArray(originalArray, n);

    quickSort(originalArray, 0, n - 1);

    cout << "Sorted array : ";
    printArray(originalArray, n);

    return 0;
}
