#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_palindrome(char* word){
    int start = 0;
    int end = strlen(word)-1;

    while (end > start){
        if (word[start++] != word[end--]){
            return 0; // not palindrome
        }
    }
    return 1; // it is palindrome
}

void str_copy(char* A, char* B){
    int len_a = strlen(A);
    int size_b = sizeof(B);
    if (size_b-1 < len_a){
        printf("size of B is smaller than A, can't copy\n");
        return;
    }

    //직접 복사
    for (int i=0; i < len_a;i++){
        B[i]= A[i];
    }
    B[len_a] = '\0';
}

