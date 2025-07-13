//
//  main.c
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/06/28.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxArrayLength 17


void reverse_slow(char* string){
    char temp[maxArrayLength];
    int length = 0;
    char* start = string;
    while((*string) != '\0'){
        length ++;
        string ++;
    }
    int index = 0;
    for(; index < length; index ++){
        temp[index] = start[length - index - 1];
    }
    temp[index] = '\0';
    strcpy(start, temp);
}

void reverse(char* string){
    int length = 0;
    char* pointer = string;
    while((*pointer) != '\0'){
        pointer ++;
        length ++;
    }
    char* start = string;
    char* end = (pointer - 1);
    if((*start) == '+' || (*start) == '-'){
        start ++;
    }
    while(start < end){
        char temp;
        temp = (*start);
        (*start) = (*end);
        (*end) = temp;
        start ++;
        end --;
    }
}

void complement(char* input){
    char* pointer = input;
    while((*pointer) != '\0'){
        /*ASCII code of character 'A': 65 */
        /*ASCII code of character '0': 48 */
        if((*pointer) <= '5' && (*pointer) >= '0'){
            int number = (*pointer) - '0';
            (*pointer) = (char)('F' - number);
        }else if((*pointer) >= '6' && (*pointer) <= '9'){
            int number = (*pointer) - '0';
            (*pointer) = (char)('9' - number);
        }else{
            int number = (*pointer) - 'A' + 10;
            int remainder = 15 - number;
            (*pointer) = '0' + remainder;
        }
        pointer ++;
    }
}

int characterToInteger(char* character){
    int result = 0;
    if((*character) <= '9' && (*character) >= '0'){
        result = (*character) - '0';
    }else if((*character) <= 'F'){
        result = (*character) - 'A' + 10;
    }
    return result;
}

char integerToCharacter(int* number){
    char result = '0';
    if((*number) <=9 && (*number) >= 0){
        result = '0' + (*number);
    }else if((*number) <= 15){
        result = 'A' + (*number) - 10;
    }
    return result;
}

char* addition(char* operand1, char* operand2){
    reverse(operand1);
    reverse(operand2);
    char* result = (char*)malloc(sizeof(char) * maxArrayLength);
    char* resultIndex = result;
    char* string1 = operand1;
    char* string2 = operand2;
    int number1 = 0;
    int number2 = 0;
    int carry = 0;
    int sum = 0;
    while((*string1) != '\0' && (*string2) != '\0'){
        number1 = characterToInteger(string1);
        number2 = characterToInteger(string2);
        sum = number1 + number2 + carry;
        carry = sum / 16;
        sum = sum - carry * 15;
        (*resultIndex) = integerToCharacter(&sum);
        string1 ++;
        string2 ++;
        resultIndex ++;
    }
    if((*string1) == '\0'){
        while((*string2) != '\0'){
            number2 = characterToInteger(string2);
            sum = carry + number2;
            carry = sum / 16;
            sum = sum - carry * 15;
            (*resultIndex) = integerToCharacter(&sum);
            string2 ++;
            resultIndex ++;
        }
    }else if ((*string2) == '\0'){
        while((*string1) != '\0'){
            number1 = characterToInteger(string1);
            sum = carry + number1;
            carry = sum / 16;
            sum = sum - carry * 15;
            (*resultIndex) = integerToCharacter(&sum);
            string1 ++;
            resultIndex ++;
        }
    }
    if(carry == 1){
        (*resultIndex) = integerToCharacter(&carry);
        resultIndex ++;
    }
    (*resultIndex) = '\0';
    reverse(result);
    return result;
}



int main(int argc, const char* argv[]){
//    char numA[maxArrayLength], numB[maxArrayLength];
//    scanf("%s %s", numA, numB);
//    reverse(numA);
//    printf("%s\n", numA);
//    char num[5] = "ABCD";
//    complement(num);
//    printf("%s\n", num);
    return 0;
}
