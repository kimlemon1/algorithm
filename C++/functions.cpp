#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <map>
#include <list>


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

bool check_substring(string s, string t){
    int len_s = s.size();
    int len_t = t.size();
    int flag = 0;
    
    for (int i=0; i < len_s;i++){
        
        if (s[i]==t[0] && len_s-i >= len_t){
            for (int j=0; j < len_t; j++){
                if(s[i+j]==t[j]) flag=1;
                else {
                    flag=0;
                    break;
                }
            }
            if (flag==1) break;
        }
    }
    
    return (bool)flag;
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

// 처음 값, 끝값
// vector.front();
// vector.back();

// vector.begin() : 시작 지점 포인터
// vector.end() : end_idx + 1 번째 포인터


// 해당 값이 벡터 안에 없으면 v.end() 리턴
//find(v.begin(), v.end(), 찾을 대상)
// 해당 값의 인덱스 찾기
//find(v.begin(), v.end(), 찾을 대상) - v.begin()

// 벡터, string i번째 인덱스 값 지우기
//vec.erase(vec.begin()+i)

//map의 key 값으로 된 리스트 만들기 
vector<int> get_key_vector_from_map(map<int,vector<int>> m){
    vector<int> key;

    for(map<int,vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
        key.push_back(it->first);
    }
    return key;
}


// string to char

char ch[100];
string a = "I wanna go to bed";
strcpy(ch,a.c_str());

cout<<ch<<endl;

// char to string

char ch2[100] = {"Oh my god"};
string str(ch2);

cout <<str<<endl;