//
//  main.cpp
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/06/27.
//





#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define range 5

typedef struct chainedNode{
    int value;
    int index;
    struct chainedNode* next;
}chainedNode;

chainedNode* table[range] = {NULL};

int hashFunction(int value){
    int key = 0;
    key = value % range;
    return key;
}

void insert(int value, int index){
    int key = hashFunction(value);
    chainedNode* newAddr = (chainedNode*) malloc (sizeof (chainedNode));
    (*newAddr).value = value;
    (*newAddr).index = index;
    (*newAddr).next = table[key];
    table[key] = newAddr;
}

void clean(){
    for(int cnt = 0; cnt < range; cnt++){
        free(table[cnt]);
    }
}

int search(int target){
    int index = -1;
    int key = hashFunction(target);
    chainedNode* check = table[key];
    while (check != NULL){
        if((*check).value == target){
            index = (*check).index;
            break;
        }else{
            check = (*check).next;
        }
    }
    return index;
}

int main(int argc, const char * argv[]) {
    int arrayLength, target, result = -1;
    printf("Length of array:\n");
    scanf("%d",&arrayLength);
    int array[arrayLength];
    printf("Array:\n");
    for(int index=0; index < arrayLength; index++){
        scanf("%d", &array[index]);
        insert(array[index], index);
    }
    printf("Target value:\n");
    scanf("%d", &target);
    int counter = 0;
    for(; counter < arrayLength; counter++){
        result = search(target - array[counter]);
        if(result != -1 && result != counter){
            break;
        }
    }
    if(result != -1){
        printf("%d, %d\n", counter, result);
    }else{
        printf("Not found");
    }
    clean();
    return 0;
}
