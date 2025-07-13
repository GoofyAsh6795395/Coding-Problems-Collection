//
//  main.c
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/07/12.
//
/**
 * @brief 50. Pow(x, n)
 *
 * @problem
 * Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., x^n).
 *
 * @solution_approach
 * A naive solution of multiplying `x` by itself `n` times would be too slow and
 * result in a "Time Limit Exceeded" error.
 * This solution uses a highly efficient recursive approach known as
 * **Exponentiation by Squaring** (or Fast Power Algorithm).
 * The core idea is based on the principle of divide and conquer:
 *  - If n is even, x^n = (x^2)^(n/2).
 *  - If n is odd,  x^n = x * (x^2)^((n-1)/2).
 * The implementation also correctly handles negative exponents by computing 1.0 / pow(x, -n).
 *
 * @complexity
 * Time Complexity: O(log n), because we halve the problem size at each recursive step.
 * Space Complexity: O(log n), due to the depth of the recursion stack.
 *
 * @example
 *  Example 1:
 *  Input: x = 2.00000, n = 10
 *  Output: 1024.00000
 *
 *  Example 2:
 *  Input: x = 2.00000, n = -2
 *  Output: 0.25000 (Explanation: 2^-2 = 1/2^2 = 0.25)
 */


#include <stdio.h>

double power(double base, long exponent){
    /**Dealing with overflow requires attention at this stage*/
    /**Consider the range of exponent*/
    double result = 1;
    if(exponent < 0){
        return 1.0/power(base, -exponent);
    }
    if(exponent == 0){
        return 1.0;
    }
    if(exponent == 1){
        return base;
    }
    double half = power(base, exponent / 2);
    if(exponent % 2 == 0){
        result = half * half;
    }else{
        result = half * half * base;
    }
    return result;
}

int main(int agrc, const char* argv[]){
    long exponent = 1;
    double result, base = 1;
    scanf("%lf %ld", &base, &exponent);
    result = power(base, exponent);
    printf("%lf", result);
    return 0;
}
