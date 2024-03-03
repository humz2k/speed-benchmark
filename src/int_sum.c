#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "cputimer.h"

int* init_array(int n){
    int* array;
    CPUTimer_t malloc_start = CPUTimer();
    assert(array = (int*)malloc(sizeof(int) * n));
    CPUTimer_t malloc_end = CPUTimer();
    print_timer(malloc_start,malloc_end,"malloc");

    CPUTimer_t assign_start = CPUTimer();
    for (int i = 0; i < n; i++){
        array[i] = i;
    }
    CPUTimer_t assign_end = CPUTimer();
    print_timer(assign_start,assign_end,"assign");

    return array;
}

int sum_array(int* array, int n){
    CPUTimer_t sum_start = CPUTimer();
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += array[i];
    }
    CPUTimer_t sum_end = CPUTimer();
    print_timer(sum_start,sum_end,"sum");
    return sum;
}

int run_int_sum(int n){
    CPUTimer_t total_start = CPUTimer();
    int* array = init_array(n);
    int ans = sum_array(array,n);
    free(array);
    CPUTimer_t total_end = CPUTimer();
    print_timer(total_start,total_end,"total");
    return ans;
}
