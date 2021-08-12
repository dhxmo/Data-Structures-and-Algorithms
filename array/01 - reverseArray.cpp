#include<iostream>
#include<algorithm>
using namespace std;

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    } 
    cout << "\n";
}

void reverseArr(int arr[], int first, int last) {
    if (first < last) {
        swap(arr[first], arr[last]);
        reverseArr(arr, first + 1, last - 1);
    }
}

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArr(arr, size);

    cout << "Reverse array: ";
    reverseArr(arr, 0, size-1);
    printArr(arr, size);

    return 0;
}