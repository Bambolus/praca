#include "wyszukiwanie.hpp"
#include <cmath>
using namespace std;

int liniowe(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int liniowezwartownikiem(int arr[], int size, int key) {
    int last = arr[size - 1];
    arr[size - 1] = key;
    int i = 0;
    while (arr[i] != key) {
        i++;
    }
    arr[size - 1] = last;
    if ((i < size - 1) || (arr[size - 1] == key)) {
        return i;
    }
    return -1;
}

int skokowe(int arr[], int size, int key) {
    int step = sqrt(size);
    int prev = 0;
    while (arr[min(step, size) - 1] < key) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1;
        }
    }
    while (arr[prev] < key) {
        prev++;
        if (prev == min(step, size)) {
            return -1;
        }
    }
    if (arr[prev] == key) {
        return prev;
    }
    return -1;
}

int binarne(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}