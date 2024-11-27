#include "header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <chrono>
#include <random>

void printarr(std::vector <int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    using std::chrono::nanoseconds;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(1, 10000);
    using clock = std::chrono::steady_clock;
    using ns = std::chrono::nanoseconds;
     std::cout<<"size,insert,quick,heap,radix"<<std::endl;
    /*std::cout<<"Enter size begin: "<<std::endl;
    double sizeb;
    std::cin>>sizeb;
    std::cout<<"Enter size end: "<<std::endl;
    double sizend;
    std::cin>>sizend;
    std::cout<<"Enter Value : "<<std::endl;
    double val;
    std::cin>>val;
    std::cout<<"Size, Hybrid"<<std::endl;
    for (unsigned size = sizeb ; size < sizend ; size += val) {
        ns insertion_time(0), quick_time(0), heap_time(0), radix_time(0), hybrid_time(0);
        std::vector<int> arr;

        for (unsigned j = 0 ; j < size ; j++) {
            arr.push_back(dist(gen));
        }*/

    for (unsigned size = 100 ; size < 10000 ; size += 100) {
        ns insertion_time(0), quick_time(0), heap_time(0), radix_time(0), hybrid_time(0);
        std::vector<int> arr;

        for (unsigned j = 0 ; j < size ; j++) {
            arr.push_back(dist(gen));
        }
        std::vector <int> temp(arr);
        auto insertion_start = clock::now();
        insertion(temp);
        auto insertion_end = clock::now();
        insertion_time+= std::chrono::duration_cast<ns>(insertion_end - insertion_start);
        temp = arr;
        auto quick_start = clock::now();
        quick(temp, 0, temp.size() - 1);
        auto quick_end = clock::now();
        quick_time+= std::chrono::duration_cast<ns>(quick_end - quick_start);
        temp = arr;
        auto heap_start = clock::now();
        heap(temp);
        auto heap_end = clock::now();
        heap_time+= std::chrono::duration_cast<ns>(heap_end - heap_start);
        temp = arr;
        auto radix_start = clock::now();
        radix(temp);
        auto radix_end = clock::now();
        radix_time+= std::chrono::duration_cast<ns>(radix_end - radix_start);

        auto hybrid_start = clock::now();
        hybrid(temp, 0, temp.size() -1);
        auto hybrid_end = clock::now();
        hybrid_time+= std::chrono::duration_cast<ns>(hybrid_end - hybrid_start);

        std::cout << size << "," << insertion_time.count() << ","<< quick_time.count() << "," << heap_time.count() << ","<< radix_time.count() << "," << std::endl;

        //std::cout<<hybrid_time.count()<<std::endl;
    }








    //int testarray[] = {1,5,6,8,3,1,9,10 };
    //int testsize=8;
    //std::vector <int> temp {1,5,6,8,3,1,9,10};
    //insertion(temp);
    //quick(temp,0,temp.size()-1);
    //heap(temp);
    //radix(temp);
    //printarr(temp);
    //assert(std::is_sorted(temp.begin(), temp.end()));



   /* quick(testarray,0,testsize-1);
    std::cout<<"Quick : ";
    printarr(testarray,testsize);
    heap(testarray,testsize-1);
    printarr(testarray,testsize);

    printarr(testarray,testsize);
    radix(testarray,testsize-1);
    printarr(testarray,testsize);
*/
/*    int size ;
std::cout<<"Enter size:"<<std::endl;
std::cin>>size;
int arr[size];
int minv;
std::cout<<"Enter min value:"<<std::endl;
std::cin>>minv;
int maxv;
std::cout<<"Enter maximum value : "<<std::endl;
std::cin>>maxv;

    Randomizer(arr,size,minv,maxv);
    printarr(arr,size);
    quick(arr,0,size-1);
    std::cout<<"After Quick sort :"<<std::endl;
    printarr(arr,size);

*/

    return 0;
}
