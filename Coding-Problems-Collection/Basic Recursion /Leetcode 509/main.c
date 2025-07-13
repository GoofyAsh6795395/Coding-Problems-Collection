//
//  main.c
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/07/11.
//
/**
 * @brief 509. Fibonacci Number
 *
 * @problem
 * The Fibonacci numbers, commonly denoted F(n), form a sequence where
 * each number is the sum of the two preceding ones, starting from 0 and 1.
 * That is, F(0) = 0, F(1) = 1, and F(n) = F(n-1) + F(n-2) for n > 1.
 *
 * @solution_approach
 * While this problem can be solved with a simple, naive recursion, that approach
 * has an exponential time complexity of O(2^n) due to redundant calculations.
 * A far more efficient solution is to use **bottom-up Dynamic Programming**.
 * We can solve this iteratively by keeping track of only the last two Fibonacci
 * numbers to calculate the next one. This brings the time complexity down
 * to linear and space complexity to constant.
 *
 * @complexity
 * Time Complexity: O(n), since we iterate from 2 up to n.
 * Space Complexity: O(1), as we only store the two previous numbers.
 *
 * @example
 *  Example 1:
 *  Input: n = 2
 *  Output: 1 (Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1)
 *
 *  Example 2:
 *  Input: n = 4
 *  Output: 3 (Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3)
 */

#include <stdio.h>

int getFibnacci(int term){
    int result = 0;
    if(term < 1){
        return -1;
    }
    if(term == 1 || term == 2){
        return 1;
    }else{
        result = getFibnacci(term - 1) + getFibnacci(term - 2);
    }
    return result;
}

int main(int argc, const char* argv[]){
    int term;
    int result;
    scanf("n = %d", &term);
    result = getFibnacci(term);
    printf("%d", result);
    return 0;
}
