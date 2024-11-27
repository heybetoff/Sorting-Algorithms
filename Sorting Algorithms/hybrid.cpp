#include <vector>
#include <algorithm>
#include "header.h"
#include <iostream>

void hybrid(std::vector<int> &arr, int start, int end) {

    if (end - start < 30) {  //insertion

        for (int i = start + 1; i < end; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= start && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;

        }
    } else if (end - start < 1400){ //quick

        if (start < end) {
            int pivot = arr[end];
            int i = start - 1;

            for (int j = start; j < end; j++) {
                if (arr[j] < pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }

            i++;
            std::swap(arr[i], arr[end]);
            int pivotIndex = i;

            hybrid(arr, start, pivotIndex - 1);
            hybrid(arr, pivotIndex + 1, end);

        }
    } else {//radix

        int num = end - start + 1;


        int maximum = arr[start];
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] > maximum) {
                maximum = arr[i];
            }
        }


        auto countSort = [&](int power) {
            std::vector<int> output(num);
            std::vector<int> counter(10, 0);

            for (int i = start; i <= end; i++) {
                counter[(arr[i] / power) % 10]++;
            }

            for (int i = 1; i < 10; i++) {
                counter[i] += counter[i - 1];
            }

            for (int i = end; i >= start; i--) {
                output[counter[(arr[i] / power) % 10] - 1] = arr[i];
                counter[(arr[i] / power) % 10]--;
            }

            for (int i = start, j = 0; i <= end; i++, j++) {
                arr[i] = output[j];
            }

        };


        for (int power = 1; maximum / power > 0; power *= 10) {
            countSort(power);
        }
    }
}
