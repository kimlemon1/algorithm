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

void print_array(int *L, int len){
    for (int i =0; i < len; i++){
        printf("%d ", L[i]);
    }
}

void insertion_sort(int *L, int n) { // n : array length
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = L[i];
        j = i - 1;

        /* Move elements of L[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && L[j] > key) {
            L[j + 1] = L[j];
            j = j - 1;
        }
        L[j + 1] = key;
    }
}

void selection_sort(int L[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (L[j] < L[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        temp = L[min_idx];
        L[min_idx] = L[i];
        L[i] = temp;
    }
}

void merge(int L[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int* L1 = (int*)malloc(sizeof(int)*n1);
    int* R1 = (int*)malloc(sizeof(int)*n2);

    /* Copy data to temp arrays L1[] and R1[] */
    for (i = 0; i < n1; i++)
        L1[i] = L[l + i];
    for (j = 0; j < n2; j++)
        R1[j] = L[m + 1+ j];

    /* Merge the temp arrays back into L[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L1[i] <= R1[j]) {
            L[k] = L1[i];
            i++;
        } else {
            L[k] = R1[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L1[], if there
       are any */
    while (i < n1) {
        L[k] = L1[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R1[], if there
       are any */
    while (j < n2) {
        L[k] = R1[j];
        j++;
        k++;
    }
}

void merge_sort(int L[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        merge_sort(L, l, m);
        merge_sort(L, m+1, r);

        merge(L, l, m, r);
    }
}

#define MAX 10000 // Assuming the max value in list is less than 10000

void counting_sort(int list[], int n) {
    int* output = (int*)malloc(sizeof(int)*n);
    int count[MAX + 1], i;
    memset(count, 0, sizeof(count));

    for(i = 0; i<n; ++i)
        ++count[list[i]];

    for (i = 1; i <= MAX; ++i)
        count[i] += count[i-1];

    for (i = n - 1; i >= 0; i--) {
        output[count[list[i]]-1] = list[i];
        --count[list[i]];
    }

    for (i = 0; i < n; i++)
        list[i] = output[i];
}

void rvereseArray(int arr[], int start, int end) 
{ 
    int temp; 
    while (start < end) { 
        temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
} 

int find_maxval_in_array(int arr[], int n)
{
    int i;
 
    // Initialize maximum element
    int max = arr[0];
 
    // Traverse array elements from
    // second and compare every
    // element with current max
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}

void get_common_elements_array(int *array1, int *array2, int *result){

    int flag;
    int k = 0;
    for (int i = 0; i < sizeof(array1) / 4; i++) {
        
            // To traverse in array2.
            for (int j = 0; j < sizeof(array2) / 4; j++) {
            
                // To match elements of array1 with elements of
                // array2.
                if (array1[i] == array2[j]) {
                
                    flag = 0;
                
                    // To traverse in result array.
                    for (int x = 0; x < k; x++) {
                    
                        // Check whether found element is
                        // already present in result array or
                        // not.
                        if (result[x] == array1[i]) {
                            flag++;
                        }
                    }
                
                    // If we found a new element which is common
                    // in both arrays then store it in result
                    // array and print it.
                    if (flag == 0) {
                    
                        result[k] = array1[i];
                        
                        k++;
                    }
                }
            }
        }
    }


// 문자열 입력받기
char s1[10];
scanf("%s", s1);

// 여러 문자열 입력받기
char s1[5][100];
for (int i=0;i<5;i++){
    scanf("%s", s1[i]);
}
// 여러 문자열 출력
for (int i=0;i<5;i++){
    printf("%s\n", s1[i]);
}

bool check_in_array(int* arr,int arr_len, int val){
    int not_in_arr_flag = 1;
    for (int i=0; i<arr_len;i++){
        if (val == arr[i]){
            not_in_arr_flag = 0;
            break;
        }
    }
    if (not_in_arr_flag) return false;
    else return true;
}