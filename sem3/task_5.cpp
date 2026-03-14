#include <chrono>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;
/*
void BubbleSort(vector<int>& array) {
    int n = array.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void InsertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

//функция слияния двух отсортированных половин
void merge_two(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//рекурсивная функция сортировки слиянием
void merge_sort_all(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_all(arr, left, mid);
        merge_sort_all(arr, mid + 1, right);

        merge_two(arr, left, mid, right);
    }
}

void MergeSort(vector<int>& arr) {
    merge_sort_all(arr, 0, arr.size() - 1);
}


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void QuickSort(vector<int>& arr) {
    if (!arr.empty()) {
        QuickSort(arr, 0, arr.size() - 1);
    }
}

int main() {
    random_device rd;
    mt19937 gen(rd());

    vector<int> original;
    for (int i = 0; i < 100000; i++) {
        original.push_back(gen());
    }

    milliseconds duration_BubbleSort;
    milliseconds duration_InsertionSort;
    milliseconds duration_MergeSort;
    milliseconds duration_QuickSort;
    milliseconds duration_Sort;
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point end;

    vector<int> arr1 = original;
    start = high_resolution_clock::now();
    BubbleSort(arr1);
    end = high_resolution_clock::now();
    duration_BubbleSort = duration_cast<milliseconds>(end - start);

    vector<int> arr2 = original;
    start = high_resolution_clock::now();
    InsertionSort(arr2);
    end = high_resolution_clock::now();
    duration_InsertionSort = duration_cast<milliseconds>(end - start);

    vector<int> arr3 = original;
    start = high_resolution_clock::now();
    MergeSort(arr3);
    end = high_resolution_clock::now();
    duration_MergeSort = duration_cast<milliseconds>(end - start);

    vector<int> arr4 = original;
    start = high_resolution_clock::now();
    QuickSort(arr4);
    end = high_resolution_clock::now();
    duration_QuickSort = duration_cast<milliseconds>(end - start);

    vector<int> arr5 = original;
    start = high_resolution_clock::now();
    sort(arr5.begin(), arr5.end());
    end = high_resolution_clock::now();
    duration_Sort = duration_cast<milliseconds>(end - start);

    cout << "Bubble Sort: " << duration_BubbleSort.count() << " мс" << endl;
    cout << "Insertion Sort: " << duration_InsertionSort.count() << " мс" << endl;
    cout << "Merge Sort: " << duration_MergeSort.count() << " мс" << endl;
    cout << "Quick Sort: " << duration_QuickSort.count() << " мс" << endl;
    cout << "Sort: " << duration_Sort.count() << " мс" << endl;
}*/