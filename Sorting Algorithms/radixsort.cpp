#include "header.h"


int maximum(std::vector <int> &arr) {
    int m = arr[0];
    int num = arr.size();
    for (int i = 1; i < num; i++) {
        if (arr[i] > m) {
            m = arr[i];
        }
    }
    return m;
}

void count(std::vector <int> &arr, int power) {
    int num = arr.size();
    int output[num];
    int counter[10] = {0};
    for (int i = 0; i < num; i++) {
        counter[(arr[i] / power) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        counter[i] += counter[i - 1];
    }

    for (int i = num - 1; i >= 0; i--) {
        output[counter[(arr[i] / power) % 10] - 1] = arr[i];
        counter[(arr[i] / power) % 10]--;
    }

    for (int i = 0; i < num; i++) {
        arr[i] = output[i];
    }
}



void radix(std::vector <int> &arr) {
    int max = maximum(arr);

    for (int power = 1; max / power > 0; power *= 10) {
        count(arr, power);
    }
}