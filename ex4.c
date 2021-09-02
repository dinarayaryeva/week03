#include <stdio.h>

#define ARR_SIZE(x) (sizeof(x)/sizeof((x)[0]))

void swap(int* a, int* b){

    int temp = *b;
    *b = *a;
    *a = temp;
}

void quick_sort(int* arr, int arr_len){

    if (arr_len==1||arr_len==0) return;

    int* pivot = &arr[arr_len-1];

    int index = 0;
    for (int i=0; i<arr_len-1; i++){

        if (arr[i]<(*pivot)) {
            swap(&arr[i], &arr[index]);
            index++;
        }
    }
    swap(pivot, &arr[index]);
    quick_sort(arr, index);
    if (index!=arr_len-1)    quick_sort(&arr[index+1], arr_len - index-1);
}


void print_array(int* arr, int arr_len){

    for (int i=0; i<arr_len; i++){
        printf("%d\n", arr[i]);
    }
}

int main(){

    int a[5] = {4, 2, 7, 3, 6};

    quick_sort(a, ARR_SIZE(a));

    print_array(a, ARR_SIZE(a));

    return 0;
}