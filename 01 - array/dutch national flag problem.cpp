#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dnfSort(int arr[], int size) {
    int low = 0;
    int mid = 0;
    int high = size - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 0, 0, 1, 2, 2, 1, 0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    dnfSort(arr, size);

    for (int elem : arr) {
        cout << elem << " ";
    }

}