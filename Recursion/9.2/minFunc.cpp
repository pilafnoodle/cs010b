#include "minFunc.h"

//find and return the location of the smallest value in an array of integers. 
const int * min(const int arr[], int arrSize) {

    if(arrSize==0){
        return nullptr;
    }

    const int* minptr = min(arr, arrSize-1);
    if(minptr==nullptr){
        return &arr[arrSize-1];
    }

    if(*minptr<arr[arrSize-1]){
        return minptr;
    }

    return &arr[arrSize-1];

}