//
//  main.c
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/06/27.
//
// Problem: HDU 2072 - Word Count
// Source:  Hangzhou Dianzi University Online Judge (HDU ACM)

// --- Problem Description ---
// The task is to count the number of unique (distinct) words in a given text.

// --- Input Format ---
// - The input consists of multiple test cases (articles), one per line.
// - Each article is composed of lower-case English letters and spaces.
// - There are no punctuation marks.
// - A line containing only a '#' character signifies the end of a test case.
// - The input is terminated by EOF (End of File).

// --- Output Format ---
// - For each test case, print a single integer on a new line, representing
//   the total count of distinct words in the article.

// --- Sample Input ---
// you are my friend
// #
// i love you and you love me
// #

// --- Sample Output ---
// 4
// 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define wordLength 100

trieNode trieRoot = {0, 0, NULL, NULL, NULL};

int main(int argc, const char* argv[]){
    /*Possible inputs: letter, ' ', '\0', '\n' '#'*/
    char word[wordLength];
    int index = 0;
    int counter = 0;
    while((word[index] = getchar()) != '#'){
        if(word[index] == '\n'){
            word[index] = '\0';
            int found = trieSearch(word);
            if(found == 0){
                trieInsert(word);
                counter ++;
            }
            printf("%d\n", counter);
            memset(word, 0, sizeof(word));
            index = 0;
            counter = 0;
            trieDelete(trieRoot.leftChild);
            trieRoot.leftChild = NULL;
        }else if(word[index] == ' '){
            word[index] = '\0';
            int found = trieSearch(word);
            if(found == 0){
                trieInsert(word);
                counter ++;
            }
            memset(word, 0, sizeof(word));
            index = 0;
        }else{
            index ++;
        }
    }
    return 0;
}
