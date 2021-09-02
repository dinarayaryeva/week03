#include <stdio.h>

#define ARR_SIZE(x) (sizeof(x)/sizeof((x)[0]))

void swap(int* a, int* b){

    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubble_sort(int* arr, int arr_len){

    for (int i = 0; i < arr_len - 1; i++){
        for (int k = 0; k < arr_len - i - 1; k++){
            if (arr[k] > arr[k+1]) swap(&arr[k], &arr[k+1]);
        }
    }
}

void print_array(int* arr, int arr_len){

    for (int i=0; i<arr_len; i++){
        printf("%d\n", arr[i]);
    }
}

int main(){

    int a[5] = {1, 2, 7, 3, 1};

    bubble_sort(a, ARR_SIZE(a));

    print_array(a, ARR_SIZE(a));

    return 0;
}
