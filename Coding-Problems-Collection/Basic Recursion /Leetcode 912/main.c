//
//  main.c
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/07/12.
//
/**
 * @brief 912. Sort an Array
 *
 * @problem
 * Given an array of integers `nums`, sort the array in ascending order.
 * This problem is a fundamental exercise in implementing sorting algorithms
 * without using built-in library functions.
 *
 * @solution_approach
 * This implementation utilizes the Quick Sort algorithm, a classic divide-and-conquer
 * sorting method. The key steps are:
 * 1. A pivot element is chosen (in this implementation, it's randomized to avoid
 *    worst-case performance on sorted arrays).
 * 2. The array is partitioned in-place into two sub-arrays around the pivot,
 *    such that all elements smaller than the pivot come before it, and all
 *    elements greater come after. This implementation uses a custom Hoare-like
 *    partition scheme.
 * 3. The `quickSort` function is recursively called for the two sub-arrays.
 *
 * @complexity
 * Time Complexity: O(n log n) on average, O(n^2) in the worst case.
 * Space Complexity: O(log n) on average, for the recursion stack depth.
 *
 * @example
 *  Example 1:
 *  Input: nums = [5,2,3,1]
 *  Output: [1,2,3,5]
 *
 *  Example 2:
 *  Input: nums = [5,1,1,2,0,0]
 *  Output: [0,0,1,1,2,5]
 */


#include <stdio.h>
#include <stdlib.h>

#define length_max 100

void swap(int* A, int* B){
    int temp = 0;
    temp = (*A);
    (*A) = (*B);
    (*B) = temp;
}

int partition(int left, int right, int* array){
    int pivotPosition = rand() % (right - left) + left;
    int pivot = (*(array + pivotPosition));
    while(left < right){
        while(left < right && (*(array + left)) < pivot){
            left ++;
        }
        if(left >= right){
            break;
        }
        while(left< right && (*(array + right)) >= pivot){
            right --;
        }
        if(left >= right){
            break;
        }else{
            swap(array + left, array + right);
        }
    }
    pivotPosition = left;
    return pivotPosition;
}

void quickSort(int left, int right, int* array){
    if(left >= right){
        return;
    }
    int pivot = partition(left, right, array);
    quickSort(left, pivot - 1, array);
    quickSort(pivot + 1, right, array);
    /*Note that the scale of sub-problem must be less than the origional one*/
}

int main(int agrc, const char* argv[]){
    int array[length_max];
    int length = 0;
    scanf("%d", &length);
    for(int counter = 0; counter < length; counter ++){
        scanf("%d", array + counter);
    }
    int index;
    index = partition(0, length - 1, array);
    quickSort(0, length -1, array);
    for(int counter = 0; counter < length; counter ++){
        printf("%d", array[counter]);
    }
}
