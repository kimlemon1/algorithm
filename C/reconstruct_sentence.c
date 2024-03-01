#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// problem : 
// Input : "is2 sentence4 This1 a3"
// Output : "This is a sentence"

// single char to int
int ctoi(char b){
    return b - '0';
}

// string to int


char *reconstructSentence(char *s){
    
    int len = strlen(s);
    int j = 0;

    char* word_hash[9];
    for (int j=0; j<9;j++){
        word_hash[j] = NULL;
    }

    for (int i =0; i<len+1;i++){
        if (s[i] == ' ' || s[i]=='\0'){
            
            int word_idx = ctoi(s[i-1]);
            char* temp = (char*)malloc(sizeof(char)*(i-j));
            // 항상 초기화 필수
            for (int m =0; m < i-j;m++){
                temp[m] = '\0';
            }

            for (int k=j;k < i-1;k++){
                temp[k-j] = s[k];
            }
            
            //printf("len of word : %d\n", i-j-1);

            j = i+1;
            word_hash[word_idx] = temp;
            //printf("stirng in temp : %s\n", temp);
        }
    }
    char* ans = (char*)malloc(sizeof(char)*len);
    int ans_idx = 0;
    for (int i=0; i<9;i++){
        if(word_hash[i] != NULL){
            int temp_len = strlen(word_hash[i]);
            for (int j =0; j <temp_len; j++){
                ans[ans_idx++] = word_hash[i][j];
            }
            ans[ans_idx++] = ' ';
        }
    }
    // 마지막 빈칸 제거
    ans[ans_idx-1] = '\0';
    ans[ans_idx] = '\0';
    return ans;
}

int strtoi(char* a){
    return atoi(a);
}

int main(){
    char *s = "Myself2 Me1 I4 and3";
    char *ans = reconstructSentence(s);

    printf("%s", ans);
}