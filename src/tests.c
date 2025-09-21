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
// creating point values correctly
int test_create_point_values() {
    // call the function to create a point
    Point *point = create_point(5, -2);
    // check if allocation is working
    if (point == NULL) {
        return 0;
    }
    // checking values
    if (point->x != 5) { 
        free(point); 
        return 0; 
    }
    if (point->y != -2) { 
        free(point); 
        return 0; 
    }
    // free memory in the heap
    free(point);
    // test passed
    return 1;
}
// creating a point and returning a non null value
int test_create_point_alloc() {
    Point *point = create_point(0, 0);
    // checking that won't be a null 
    if (point == NULL) {
        return 0;
    }
    // free memory in the heap
    free(point);
    return 1;
}

int test_basic_create_polygon() {
    // call the function to create a polygon
    Polygon *point = create_polygon(4);
    // checking if allocation worked or not
    if (point == NULL) {
        // if failed return 0
        return 0;
    }
    // checking with 4 and must not be null
    if (point->size != 4) {
        free_polygon(point);
        return 0;
    }
    if (point->points == NULL) {
        free_polygon(point);
        return 0;
    }
    // every element should be NULL
    for (int i = 0; i < 4; i++) {
        if (point->points[i] != NULL) {
            free_polygon(point);
            return 0;
        }
    }
    // free memory in the heap
    free_polygon(point);
    // test passed
    return 1;
}
// testing invalid sizes for creating the polygon
int test_create_polygon_invalid_size() {
    // size 0 should be invalid
    Polygon *zero = create_polygon(0);
    if (zero != NULL) {
        free_polygon(zero);
        return 0;
    }
    // negative size should also be invalid
    Polygon *negative= create_polygon(-3);
    if (negative != NULL) {
        free_polygon(negative);
        return 0;
    }
    // tests passed
    return 1;
}

// testing free_polygon with NULL
int test_free_polygon_null_safe() {
    // just checking the call with NULL
    free_polygon(NULL);
    // if passed then it should be good to go
    return 1;
}

// testing free_polygon with a basic polygon with points
int test_free_polygon_basic() {
    // create a polygon couple of points
    Polygon *p = create_polygon(2);
    if (p == NULL) {
        return 0;
    }
    // creating points for the polygon
    p->points[0] = create_point(1, 2);
    p->points[1] = create_point(3, 4);
    // free the polygon
    free_polygon(p);
    // test passed so it was free successfully
    return 1;
}
// testing create_rectangle function
int test_create_rectangle_points() {
    // calling the function
    Polygon *rectangle = create_rectangle(5, 10);
    // checking for null
    if (rectangle == NULL) {
        return 0;
    }
    // size must be 4 because it's a rectangle
    if (rectangle->size != 4) { 
        free_polygon(rectangle); 
        return 0; 
    }
    // check each expected corner of the rectangle
    if (rectangle->points[0]->x != 0 || rectangle->points[0]->y != 0)   { 
        free_polygon(rectangle); 
        return 0; 
    }
    if (rectangle->points[1]->x != 5 || rectangle->points[1]->y != 0)   { 
        free_polygon(rectangle); 
        return 0; 
    }
    if (rectangle->points[2]->x != 5 || rectangle->points[2]->y != 10)  { 
        free_polygon(rectangle); 
        return 0; 
    }
    if (rectangle->points[3]->x != 0 || rectangle->points[3]->y != 10)  { 
        free_polygon(rectangle); 
        return 0; 
    }
    // freeing the memory in the heap
    free_polygon(rectangle);
    // test passed
    return 1;
}
// checking create_triangle function
int test_create_triangle_points() {
    // calling the function
    Polygon *triangle = create_triangle(6, 4);
    // checking that it's not a null
    if (triangle == NULL) {
        return 0;
    }
    // size must be at least 3 because it's a triangle
    if (triangle->size != 3) { 
        free_polygon(triangle); 
        return 0; 
    }
    // check each corner of the triangle
    if (triangle->points[0]->x != 0 || triangle->points[0]->y != 0) { 
        free_polygon(triangle); 
        return 0; 
    }
    if (triangle->points[1]->x != 6 || triangle->points[1]->y != 0) { 
        free_polygon(triangle); 
        return 0; 
    }
    if (triangle->points[2]->x != 6 || triangle->points[2]->y != 4) { 
        free_polygon(triangle); 
        return 0; 
    }
    // freeing memory in the heap for the triangle
    free_polygon(triangle);
    // test passed
    return 1;
}

// testing area of a rectangle
int test_area_rectangle() {
    // creating a rectangle
    Polygon *r = create_rectangle(5, 10);
    if (r == NULL) {
        return 0;
    }
    // calculating area
    long area = calculate_polygon_area(r);
    // free memory in the heap
    free_polygon(r);
    // area of rectangle is width * height = 5 * 10 = 50
    if (area != 50.0) {
        return 0;
    }
    // test passed
    return 1;
}
// testing area of a triangle
int test_area_triangle() {
    // creating a triangle
    Polygon *t = create_triangle(6, 4);
    if (t == NULL) {
        return 0;
    }
    // calculating area
    long area = calculate_polygon_area(t);
    // free memory in the heap
    free_polygon(t);
    // area of triangle is (base * height) / 2 = (6 * 4) / 2 = 12
    if (area != 12.0) {
        return 0;
    }
    // test passed
    return 1;
}

int test_area_hexagon() {
    // creating a hexagon
    Polygon *hexa = create_polygon(6);
    if (hexa == NULL) {
        return 0;
    }
    // creating the six points of the hexagon
    hexa->points[0] = create_point(12, 10);
    hexa->points[1] = create_point(11, 12);
    hexa->points[2] = create_point(9, 12);
    hexa->points[3] = create_point(8, 10);
    hexa->points[4] = create_point(9, 8);
    hexa->points[5] = create_point(11, 8);
    // calculating area
    long area = calculate_polygon_area(hexa);
    // free memory in the heap
    free_polygon(hexa);
    if (area <= 0.0) {
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
        test_create_point_values,
        test_create_point_alloc,
        test_basic_create_polygon,
        test_create_polygon_invalid_size,
        test_free_polygon_null_safe,
        test_free_polygon_basic,
        test_create_rectangle_points,
        test_create_triangle_points,
        test_area_rectangle,
        test_area_triangle,
        test_area_hexagon,
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
