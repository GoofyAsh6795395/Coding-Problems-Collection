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

typedef struct trieNode{
    char letter;
    int isEnd;
    struct trieNode* leftChild;
    struct trieNode* right;
    struct trieNode* parent;
}trieNode;

trieNode trieRoot = {0, 0, NULL, NULL, NULL};

void trieInsert (char* string){
    int offset = 0;
    trieNode* buffer = &trieRoot;
    while(*(string + offset) != '\0'){
        char letter;
        letter = *(string + offset);
        trieNode* childs = (*buffer).leftChild;
        trieNode* temp = NULL;
        if((*buffer).leftChild != NULL){
            int found = 0;
            while(childs != NULL){
                if((*(childs)).letter == letter){
                    found = 1;
                    buffer = childs;
                    break;
                }else{
                    temp = childs;
                    childs = (*childs).right;
                }
            }
            if(found == 0){
                trieNode* newAddress = (trieNode*)malloc(sizeof(trieNode));
                (*newAddress).leftChild = NULL;
                (*newAddress).right = NULL;
                (*newAddress).parent = buffer;
                (*newAddress).letter = letter;
                (*newAddress).isEnd = 0;
                (*temp).right = newAddress;
                buffer = newAddress;
            }
        }else{
            trieNode* newAddress = (trieNode*)malloc(sizeof(trieNode));
            (*buffer).leftChild = newAddress;
            (*newAddress).letter = letter;
            (*newAddress).parent = buffer;
            (*newAddress).leftChild = NULL;
            (*newAddress).right = NULL;
            (*newAddress).isEnd = 0;
            buffer = newAddress;
        }
        offset++;
    }
    (*buffer).isEnd = 1;
}

//void trieSearch(char* target){
//    int found = 0;
//    int offset = 0;
//    trieNode* check = &trieRoot;
//    while((*target + offset) != '\0'){
//
//    }
//}

int main(int argc, const char* argv[]){
    char string[3][16];
    for(int counter = 0; counter < 3; counter ++){
        scanf("%s", string[counter]);
        trieInsert(string[counter]);
    }
    return 0;
}
