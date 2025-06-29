//
//  main.c
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/06/28.
//

#include <stdio.h>
#include <string.h>

#define maxArrayLength 17

void reverse(char* string){
    char temp[maxArrayLength];
    char* start = string;
    int length = 0;
    while((*string) != '\0'){
        length ++;
        string ++;
    }
    for(int index = 0; index < length; index ++){
        temp[index] = string[length - index - 1];
    }
    strcpy(string, temp);
}

int main(int argc, const char* argv[]){
    char numA[maxArrayLength], numB[maxArrayLength];
    scanf("%s %s", numA, numB);
    reverse(numA);
    printf("%s", numA);
    return 0;
}
