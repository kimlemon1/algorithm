#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>

using namespace std;

bool isPalindrome(string str) {
    int low = 0;
    int high = str.size() - 1;
 
    // Keep comparing characters while they are same
    while (low < high) {
        if (str[low] != str[high]) {
            return false; // not a palindrome.
        }
        low++; // move the low index forward
        high--; // move the high index backwards
    }
    return true; // is a palindrome     
}

// dest : 복사 받을 대상, src : 복사할 원본
// dest가 src보다 커야한다
char* strcpy(char * dest, const char* src); 
// num : 시작부터 복사할 개수 (처음부터 num개만 복사)
char* strncpy(char* dest, const char* src, size_t num);

// stentence input : getline
void sentence_input(string line){
    // 문장을 input으로 받는다
    getline(std::cin, line); 
}

// vector slicing vector[a:b]
std::vector<int> vecSlice(std::vector<int> inp, int a, int b) {
    return std::vector<int>(inp.begin() + a, inp.begin() + b);
}



// string slicing
// string.substr(a,b) // string[a:b]
// string.substr(a) // string[a:]
// string.substr() // string[:]


