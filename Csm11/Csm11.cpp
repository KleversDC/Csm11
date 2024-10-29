#include <iostream>
using namespace std;
template <typename T>
T findMax(const T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
template <typename T>
T findMin(const T* arr, int size) {
    T min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
template <typename T>
void bubbleSort(T* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
template <typename T>
int binarySearch(const T* arr, int size, T target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
template <typename T>
void replaceElement(T* arr, int size, int index, T newValue) {
    if (index >= 0 && index < size) {
        arr[index] = newValue;
    }
    else {
        cout << "Invalid index" << endl;
    }
}

int main() {
    const int size = 5;
    int arr[size] = { 4, 2, 7, 1, 9 };

    cout << "Max: " << findMax(arr, size) << endl;
    cout << "Min: " << findMin(arr, size) << endl;

    bubbleSort(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int target = 7;
    int index = binarySearch(arr, size, target);
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    }
    else {
        cout << "Element " << target << " not found" << endl;
    }

    replaceElement(arr, size, 2, 10);
    cout << "Array after replacement: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
