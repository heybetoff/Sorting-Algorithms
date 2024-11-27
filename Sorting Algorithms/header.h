#ifndef ALGHORITHMS_HEADER_H
#define ALGHORITHMS_HEADER_H
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

void quick(std::vector <int> &arr, int first, int last);
int partition(std::vector <int> &arr, int first, int last);
void printarr(int arr[], int size);
void heapify(std::vector<int> &arr, int i, int i1);
void heap(std::vector <int> &arr);
void insertion(std::vector<int> &arr);
int maximum(std::vector <int> &arr);
void count(std::vector <int> &arr, int power);
void radix(std::vector <int> &arr);
void hybrid(std::vector<int> &arr, int start, int end);














#endif //ALGHORITHMS_HEADER_H
