#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool palindrome(char *s){
    bool res = true;
    for(int i = 0; i < strlen(s)/2; i++){
        if(s[i] != s[strlen(s)-1-i]) res = false;
    }
    return res;
}

bool substring(char *s, char *t){
    bool res = false;
    if(strlen(s)<strlen(t)) return res;
    else{
        for(int i = 0; i < strlen(s)-strlen(t)+1; i++){
            bool tmp = true;
            for(int j = 0; j < strlen(t); j++){
                if(s[i+j] != t[j]) tmp = false;
            }
            if(tmp) res = tmp;
        }
        return res;
    }
}

char** max_palindrome(char *s){
    char** palin_list = (char**)malloc(sizeof(char*)*strlen(s)*strlen(s));
    int plen = 0;
    for(int i = 0; i < strlen(s); i++){
        for(int j = i+1; j < strlen(s)+1; j++){ 
            char *subs = (char*)malloc(sizeof(char)*(j-i+1));
            strncpy(subs, s+i, j-i);
            subs[j-i] = '\0';
            if(palindrome(subs)){
                palin_list[plen] = subs;
                plen++;
            }
        }
    }

    int i = 0;
    while(i < plen){
        for(int j = 0; j < plen; j++){
            if(i != j){
                if(substring(palin_list[j],palin_list[i])){
                    for(int k = i; k < plen-1; k++){
                        palin_list[k] = palin_list[k+1];
                    }
                    plen--;
                    i--;
                    break;
                }
            }
        }
        i++;
    }

    return palin_list;
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

