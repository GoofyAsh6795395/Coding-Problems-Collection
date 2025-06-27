//
//  main.c
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/06/27.
//
// Problem: HDU 2081 - Short Number
// Source:  Hangzhou Dianzi University Online Judge (HDU ACM)

// --- Problem Description ---
// The task is to convert an 11-digit mobile phone number into a 6-digit
// "short number".

// --- Conversion Rule ---
// The short number is formed by taking the last 5 digits of the mobile
// number and prefixing them with the digit '6'.
// For example, the mobile number "13512345678" corresponds to the short
// number "645678".

// --- Input Format ---
// - The first line contains an integer N (N <= 200), the number of test cases.
// - The next N lines each contain an 11-digit mobile phone number as a string.

// --- Output Format ---
// - For each of the N mobile numbers, print the corresponding 6-digit short
//   number on a new line.
// - The output order must match the input order.

// --- Sample Input ---
// 2
// 13512345678
// 13787654321

// --- Sample Output ---
// 645678
// 654321

#include <stdio.h>

int main(int argc, const char* argv[]){
    int trial = 0;
    scanf("%d", &trial);
    for(int counter = 1; counter <= trial; counter ++){
        char number[12];
        scanf("%s", number);
        char output[7];
        output[0] = '6';
        for(int index = 6; index <= 10; index++){
            output [index-5] = number[index];
        }
        printf("%s", output);
    }
}
