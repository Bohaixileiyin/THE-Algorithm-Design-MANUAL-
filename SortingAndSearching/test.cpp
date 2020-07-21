#include <iostream>
#include "mergesort.hpp"
#include "quicksort.hpp"
#include "binarysearch.hpp"
using namespace std;
int main(){
    int a[] = {0,2,35,4,3,9,5,69,7,5,9};
    mergesort(a, 0, sizeof(a) / sizeof(int) - 1);
    for(auto &i:a){
        cout << i << ",";
    }
    cout << endl;

    int b[] = {0,2,35,4,3,9,5,69,7,5,9};
    quicksort(b, 0, sizeof(b) / sizeof(int) - 1);
    for(auto &i:b){
        cout << i << ",";
    }
    cout << endl;

    cout << binary_search(b, 9, 0, sizeof(b) / sizeof(int) - 1) << endl;
    cout << binary_search(b, 100, 0, sizeof(b) / sizeof(int) - 1) << endl;
}