#include "header.h"


void heapify(std::vector<int> &arr, int num, int i) {
    int biggest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if (leftchild < num && arr[leftchild] > arr[biggest])
        biggest = leftchild;

    if (rightchild < num && arr[rightchild] > arr[biggest])
        biggest = rightchild;

    if (biggest != i) {
        std::swap(arr[i], arr[biggest]);
        heapify(arr, num, biggest);
    }
}

void heap(std::vector<int> &arr) {
    int num = arr.size();


    for (int i = num / 2 - 1; i >= 0; i--)
        heapify(arr, num, i);


    for (int i = num - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}