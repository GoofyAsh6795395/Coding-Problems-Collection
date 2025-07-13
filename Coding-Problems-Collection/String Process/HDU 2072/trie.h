//
//  trie.h
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/07/04.
//

#ifndef trie_h
#define trie_h

#include <stdlib.h>
#include <string.h>

#define initialised(node) (node != NULL)

typedef struct trieNode{
    char letter;
    int isEnd;
    struct trieNode* leftChild;
    struct trieNode* right;
    struct trieNode* parent;
}trieNode;

extern trieNode trieRoot;

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

/*Refactor Required to enhance the logic and readability*/
int trieSearch(char* target){
    int found = 1;
    int offset = 0;
    trieNode* check = trieRoot.leftChild;
    trieNode* temp = check;
    if(initialised(check)){
        while((*(target + offset)) != '\0'){
            int foundLetter = 0;
            while(check != NULL){
                if((*check).letter == (*(target + offset))){
                    /*Case: A single letter matches with the target string*/
                    foundLetter = 1;
                    temp = check;
                    break;
                }
                temp = check;
                check = (*check).right;
            }
            if(foundLetter == 0){
                found = 0;
                break;
            }else{
                /*Update the node to the corresponding child one for the upcoming check*/
                if((*temp).leftChild != NULL){
                    check = (*temp).leftChild;
                }else{
                    check = NULL;
                }
            }
            offset ++;
        }
    }else{          /*Case: No node has been inserted in the trie tree*/
        found = 0;
    }
    if(initialised(check)){
        if((*temp).isEnd == 0){
            found = 0;
        }
    }
    return found;
}

void trieDelete(trieNode* node){
    if(node == NULL){
        return;
    }
    trieDelete((*node).leftChild);
    (*node).leftChild = NULL;
    trieDelete((*node).right);
    (*node).right = NULL;
    free(node);
}

#endif /* trie_h */
