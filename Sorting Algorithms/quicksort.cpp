#include "header.h"




void quick(std::vector <int> &arr, int first, int last){

    if (first < last) {
        int pivotIndex = partition(arr, first, last);


        quick(arr, first, pivotIndex - 1);
        quick(arr, pivotIndex + 1, last);
    }

}



int partition(std::vector <int> &arr, int first, int last) {
    int pivot = arr[last];
    int i = first - 1;

    for (int j = first; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    i++;
    std::swap(arr[i], arr[last]);
    return i ;
}


