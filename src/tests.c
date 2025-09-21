/**
 * Student Name: Najib Mosquera
 * Semester: Fall 2025
 * 
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library

#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

/**
 * Tests a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

int test_swap_two(){
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

/**
 * Tests the create_array_of_ints_fib function
*/

int test_create_array_of_ints_fib() {
    printf("1. test_create_array_of_ints_fib()\n");
    // calling function to create fib array of size 5
    int* arr = create_array_of_ints_fib(5);
    
    // fib numbers when size is 5 are 1, 1, 2, 3, 5
    int expected[] = {1, 1, 2, 3, 5};
    // comparing every value in the array of what we got to the expected values
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            // if any value is wrong then free memory
            free(arr);
            // return 0 for fail test
            return 0;
        }
    }

    // after checking all values and being matched then we free memory
    free(arr);
    // test passed
    return 1;
}

int test_create_array_of_ints_fib_edge_cases() {
    // checking size 1 for fib
    printf("2. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(1);
    if (arr == NULL) {
        return 0;
    }
    if (arr[0] != 1) {
        // freeing memory
        free(arr);
        return 0;
    }
    // freeing heap memory
    free(arr);
    
    // checking size 0 for fib
    int *arr2 = create_array_of_ints_fib(0);
    if (arr2 != NULL) {
       // freeing memory
        free(arr2);
        return 0;
    }
    // after checking both edge cases and passing then we get return 1
    return 1;
}

int test_reverse_array_one(){
    // creating array on stack
    int nums[] = {1, 2, 3, 4};
    // calling function to reverse the array
    reverse_array(nums, 4);
    // expected values after reversing the array

    if (nums[0] != 4) {
        return 0;
    }
    if (nums[1] != 3) {
        return 0;
    }
    if (nums[2] != 2) {
        return 0;
    }
    if (nums[3] != 1) {
        return 0;
    }
    // if all test passed then we return 1
    return 1;
}

int test_reverse_array_edge_cases() {
    // single value array
    int one_value[] = {10};
    reverse_array(one_value, 1);
    if (one_value[0] != 10) {
        // returns test failed
        return 0;
    }

    // array with null with size 0
    reverse_array(NULL, 0);

    // both checks passed
    return 1;
}

// testing double_array function
// [1, 2, 3] -> [1, 2, 3, 0, 0, 0]

int test_double_array(){
    // original array this is on stack
    int original[] = {1, 2, 3};
    // calling function to double the array
    int* new_arr = double_array_size(original, 3);
    // checking if allocation worked or not
    if(new_arr == NULL){
        return 0;
    }
    if(new_arr[0] != 1){
        free(new_arr);
        return 0;
    }
    if(new_arr[1] != 2){
        free(new_arr);
        return 0;
    }
    if(new_arr[2] != 3){
        free(new_arr);
        return 0;
    }
    // freeing memory in the heap
    free(new_arr);
    // test passed
    return 1;
}

// testing new values are zeros after doubling
int test_double_array_zeros(){
    // original array on stack
    int original[] = {1, 2, 3};
    // calling function to double the array
    int* new_arr = double_array_size(original, 3);
    // checking if allocation worked or not
    if(new_arr == NULL){
        return 0;
    }
    if(new_arr[3] != 0){
        free(new_arr);
        return 0;
    }
    if(new_arr[4] != 0){
        free(new_arr);
        return 0;
    }
    if(new_arr[5] != 0){
        free(new_arr);
        return 0;
    }
    // freeing memory in the heap
    free(new_arr);
    // test passed
    return 1;
}

//testing copy_array_start_end_loop function with simple test - no looping
int test_copy_array_start_end_no_wrap() {
    // original array on stack
    int arr[] = {1, 2, 3, 4, 5};
    // this will hold the size of the new array
    int new_size = 0;
    // calling the function returns the array in the heap
    int *result_array = copy_array_start_end_loop(arr, 5, 1, 3, &new_size);
    // if the function failed to allocate then it will return NULL
    if (result_array == NULL) {
         // test failed
        return 0;
    }
    // expecting 3 elements: [2,3,4]
    if (new_size != 3) { 
        free(result_array); 
        return 0; 
    }
    if (result_array[0] != 2) { 
        free(result_array); 
        return 0; 
    }
    if (result_array[1] != 3) { 
        free(result_array); 
        return 0; 
    }
    if (result_array[2] != 4) {
        free(result_array);
        return 0; 
    }
    // free memory in the heap
    free(result_array);

    // test passed
    return 1;
}

// testing copy_array_start_end_loop function with wrapping
int test_copy_array_start_end_wrap() {    
    // original array on stack
    int arr[] = {1, 2, 3, 4, 5};
    // this will hold the size of the new array
    int new_size = 0;
    // call the function creating new array in the heap
    int *result_array = copy_array_start_end_loop(arr, 5, 3, 1, &new_size);
    // if the function fails test fails
    if (result_array == NULL) {
        return 0;
    }
    // check the size
    if (new_size != 4) { 
        free(result_array);
        return 0;
    }
    // check the expected values
    if (result_array[0] != 4) { 
        free(result_array); 
        return 0; 
    }
    if (result_array[1] != 5) { 
        free(result_array); 
        return 0; 
    }
    if (result_array[2] != 1) { 
        free(result_array); 
        return 0; 
    }
    if (result_array[3] != 2) {
        free(result_array); 
        return 0; 
    }
    // free memory since it came from malloc inside the function
    free(result_array);

    // tests passed
    return 1;
}

// testing for invalid cases with the indexing
int test_copy_array_start_end_invalid() {
    // original array on stack
    int arr[] = {1, 2, 3, 4, 5};
    // will hold size
    int new_size = 0;
    // starting negative
    int *result_a = copy_array_start_end_loop(arr, 5, -1, 2, &new_size);
    if (result_a != NULL) {
        free(result_a);
        return 0;
    }
    // ending too big
    int *result_b = copy_array_start_end_loop(arr, 5, 0, 5, &new_size);
    if (result_b != NULL) {
        free(result_b);
        return 0;
    }
    // bad start (>= size)
    int *result_c = copy_array_start_end_loop(arr, 5, 9, 1, &new_size);
    if (result_c != NULL) {
        free(result_c);
        return 0;
    }
    // test passed
    return 1;
}

// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_create_array_of_ints_fib,
        test_swap_two,
        test_create_array_of_ints_fib_edge_cases,
        test_reverse_array_one,
        test_reverse_array_edge_cases,
        test_double_array,
        test_double_array_zeros,
        test_copy_array_start_end_no_wrap,
        test_copy_array_start_end_wrap,
        test_copy_array_start_end_invalid,

        // add more test function names here
};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
