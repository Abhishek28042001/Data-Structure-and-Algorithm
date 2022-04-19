// binary search

#include<iostream>
using namespace std;

int binary_search(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int mid = (start + end)/2;
    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid]>key){
            end = mid-1;
        }
        if(arr[mid]<key){
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    cout<< binary_search(arr, 5, 3);
    return 0;
}