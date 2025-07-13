//
//  main.c
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/06/27.
//
// Problem: HDU 2091 - Hollow Character Triangle
// Source: Hangzhou Dianzi University Online Judge (HDU ACM)

// --- Problem Description ---
// The task is to print a hollow isosceles triangle using a given character.
// The triangle should have its apex at the top and its base at the bottom.

// --- Input Format ---
// - The input consists of multiple test cases.
// - Each line contains a character 'c' and an integer 'n' (0 < n < 41).
// - 'c' is the character used to draw the triangle.
// - 'n' is the height of the isosceles triangle.
// - The input is terminated by a line starting with the '@' character.

// --- Output Format ---
// - For each test case, print the corresponding hollow triangle.
// - The apex (first row) and the base (last row) of the triangle are solid.
// - The intermediate rows are hollow.
// - The total width of the base is 2n-1.
// - There should be a blank line between the output of different test cases.
// - There should be no trailing spaces at the end of any line.

// --- Sample Input ---
// X 2
// A 7
// @

// --- Sample Output ---
//  X
// XXX
//
//       A
//      A A
//     A   A
//    A     A
//   A       A
//  A         A
// AAAAAAAAAAAAA


#include <stdio.h>

int main(int argc, const char* argv[]){
    char pattern;
    int height = 0;
    while((pattern = getchar()) != '@'){
        if(pattern != '\n'){
            scanf("%d", &height);
            int spaceNumber;
            for(int level = 1; level <= height; level++){
                spaceNumber = height - level;
                for(int cnt = 1; cnt <= spaceNumber; cnt++){
                    printf(" ");
                }
                if(level == 1){
                    printf("%c", pattern);
                }else if(level == height){
                    for(int cnt = 1; cnt <= (2 * height - 1); cnt++){
                        printf("%c", pattern);
                    }
                }else{
                    printf("%c", pattern);
                    for(int cnt = 1; cnt <= (2 * level - 3); cnt++){
                        printf(" ");
                    }
                    printf("%c", pattern);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
