//
//  main.c
//  Coding-Problems-Collection
//
//  Created by 朱欣瑞 on 2025/06/27.
//
//Problem Description:
//Find the word that appears most frequently in each test case
//
//Input:
//Multiple test cases. Each case starts with an integer N (0 < N <= 1000), denoting the number of words.
//The next N lines contain one string each.
//The word is a string of up to 15 lower-case letters.
//A case with N = 0 terminates the input.

//Output:
//For each case, print the most popular word on a single line.
//It is guaranteed that there is a unique solution for each case.

//Sample Input:
//5
//green
//red
//blue
//red
//red
//3
// pink
// orange
// pink
// 0

//Sample Output:
//red
//pink

#include <stdio.h>
#include <string.h>

typedef struct{
    char name[16];
    int frequency;
}word;

int main(int argc, const char* argv[]){
    int quantity = 0;
    while(scanf("%d", &quantity) == 1 && quantity != 0){
        word data[quantity + 1];
        int valid = 0;
        for(int counter=1; counter <= quantity; counter++){
            char input[16];
            scanf("%s", input);
            int found = 0;
            int search;
            for(search = 0; search < valid; search++){
                int position = 0;
                while(data[search].name[position] == input[position]){
                    if(input[position] == '\0'){
                        found = 1;
                        break;
                    }else{
                        position += 1;
                    }
                }
                if(found == 1){
                    break;
                }
            }
            if(found == 1){
                data[search].frequency += 1;
            }else{
                strcpy(data[valid].name, input);
                data[valid].frequency = 1;
                valid ++;
            }
        }
        int index_target = 0;
        int frequency_max = 0;
        for(int index = 0; index < valid; index ++){
            if(frequency_max < data[index].frequency){
                frequency_max = data[index].frequency;
                index_target = index;
            }
        }
        printf("%s\n", data[index_target].name);
    }
    return 0;
}
