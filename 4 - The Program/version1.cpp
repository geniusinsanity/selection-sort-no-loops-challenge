// Version 2: selection sort with no for/while/do, no recursion, no goto.
// The array and its size are written in the code.
// Repetition comes from building an array of objects: new T[n] calls T() n times.
// The boolean (a[j] < a[mn]) decides which element is the smallest.
#include <iostream>
void swap(int &x , int &y);
void selectionSort(int arr[], int size);

int *arr_ptr, n, i, j, min_index;

struct Inner {                 // inner "loop": runs n-i-1 times
    Inner() {
        j++;
        if(arr_ptr[j]<arr_ptr[min_index]){
            min_index=j;
        }
        // min_index = (arr_ptr[j] < arr_ptr[min_index]) ? j : min_index;   // boolean decision
    }
};

struct Outer {                 // outer "loop": runs n times
    Outer() {
        min_index = i;
        j = i;
        new Inner[n - i - 1];
        swap(arr_ptr[i],arr_ptr[min_index]);
        i++;
    }
};



int main() {
    int array[] = {2, 5, 333, 1, 6, 4,12,93,0,3,3,23,54,200};
    int size =sizeof(array)/sizeof(array[0]);

    selectionSort(array, size);
    for(int i=0;i<size;i++){
        std::cout<<array[i]<<" ";
    }
    // printArray(array, size);
}

void selectionSort(int arr[], int size) {   // sorts the array in place
    arr_ptr = arr;
    n = size;
    i = 0;                                 // reset, so it works many times
    new Outer[n];
}

void swap(int &x,int &y){
    int temp = arr_ptr[i];
    arr_ptr[i] = arr_ptr[min_index];
    arr_ptr[min_index] = temp;
}