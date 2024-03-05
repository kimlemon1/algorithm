#include "WordCounter.h"
#include <sstream>
#include <list>
using namespace std;

void WordCounter::InputText(const std::string &atext){
    text = atext;
}
// 빈칸 말고 단어 하나씩 받아서 개수 세는 방법 찾아보자 
int WordCounter::GetWordCount(){
    int num = 0;
    stringstream sentence(text);
    string word;
    while (sentence >> word){
        num++;
    }
    return num;
}

int WordCounter::GetCharacterCount(){
    int char_num = 0;
    for (char ch: text){
        if ((ch != ' ') && (ch != '.') && (ch != ',')){// && (ch!='\0')){
            char_num++;
        }
    }
    return char_num;
}

int WordCounter::GetUniqueWordCount(){
    
    string word;
    list<string> unique_words;
    stringstream sentence(text);
    int unique_num = 0;

    while (sentence >> word){
        if (word.back() == ',' || word.back() == '.'){
            word.pop_back();
        }

        bool unique = true;
        for (string u_word : unique_words){
            if (u_word == word) unique = false;
        }
        if (unique) {
            unique_words.push_back(word);
            unique_num++;
        }
    }
    return unique_num;
}

int WordCounter::GetWordCount_OneWord(const char* word){ // const 안쓰면 불가, 왜냐하면 단순 문자열을 메모리에 기록되어야 포인터로 주소를 얻을 수 있다.
// 그래서 const로 메모리 global var 위치에 넣음
    int count = 0;
    string find_word(word);
    string text_word;
    stringstream sentence(text);
    while (sentence >> text_word){
        if (text_word.back() == '.' || text_word.back() == ','){
            text_word.pop_back();
        }
        if (text_word == find_word) count++;
        
    }
    return count;
}