//
//  main.c
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/07/11.
//
/**
 * @brief 344. Reverse String
 *
 * @problem
 * Write a function that reverses a string. The input string is given as
 * an array of characters `char[]`.
 * You must do this by modifying the input array in-place with O(1) extra memory.
 *
 * @solution_approach
 * This is a classic application of the **Two-Pointer technique**.
 * Two pointers are initialized: `left` at the beginning of the array and `right`
 * at the end.
 * The pointers move towards each other, and at each step, the characters
 * they point to are swapped.
 * The process stops конкурират the pointers meet or cross, effectively reversing the entire array.
 *
 * @complexity
 * Time Complexity: O(n), as we iterate through roughly half of the array.
 * Space Complexity: O(1), as the reversal is done in-place.
 *
 * @example
 *  Example 1:
 *  Input: s = ["h","e","l","l","o"]
 *  Output: ["o","l","l","e","h"]
 *
 *  Example 2:
 *  Input: s = ["H","a","n","n","a","h"]
 *  Output: ["h","a","n","n","a","H"]
 */


#include <stdio.h>
#include <string.h>
#define stringLength 100000

void reverse(char* string, unsigned long left, unsigned long right){
    if(left >= right){
        return;
    }else{
        char temporary;
        temporary = (*(string + left));
        (*(string + left)) = (*(string + right));
        (*(string + right)) = temporary;
        reverse(string, left + 1, right -1);
    }
}

int main(int argc, const char* argv[]){
    char string[stringLength];
    scanf("%s", string);
    unsigned long length = strlen(string);
    reverse(string, 0, length - 1);
    printf("%s", string);
    return 0;
}
