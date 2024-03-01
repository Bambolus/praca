#include "sortowanie.hpp"
#include <cmath>
using namespace std;

void bombelkowe(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void koktajlowe(int arr[], int size) {
    bool swapped = true;
    int start = 0, end = size-1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
        end--;
        for (int i = end-1; i >= start; i--) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        start++;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;

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

void scalanie(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    scalanie(arr, l, m);
    scalanie(arr, m + 1, r);
    merge(arr, l, m, r);
}

void szybkiesortowanie(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        szybkiesortowanie(arr, low, pi - 1);
        szybkiesortowanie(arr, pi + 1, high);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

