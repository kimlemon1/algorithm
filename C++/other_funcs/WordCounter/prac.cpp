#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
void print_word(const char* word){
    int i = 0;
    
    while (word[i] != '\0'){
        char ch = word[i];
        std::cout << ch << " ";
        i++;
    }
}


vector<string> split_sentence(std::string text){
    std::string word;
    std::stringstream sentence(text);

    std::vector<std::string> words(0);
    while(sentence >> word){
        if (word.back() == '.' or word.back() == ','){
            word.pop_back();
        }
        words.push_back(word);
        //std::cout << word << " ";
    }
    //std::cout << std::endl;
    for (auto i: words){
        //std::cout << i << " ";
    }
    return words;
}

int GetWordCount_OneWord(const char * word, std::string text){
    vector<string> Word_list = split_sentence(text);
    string get_word(word);
    int num = 0;
    for (string word: Word_list){
        if (word == get_word){
            num++;
        }
    }
    return num;
}

// lect3_prac 과 함께 보자 
int main(){
    // cin은 자동으로 단어 단위로 끊는다. (빈칸 만나면 끊음)
    
    //print_word("hello my friend");

    std::string str1 = "Hello!";
    std::string str2 = "Hello!";
    //std::cout << bool(str1 == str2);


    // 문자열 배열 string 초기화 때 한번에 넣기 가능하다! 
    const char * pt_c = "Hello!";
    std::string s(pt_c);
    //std::cout << pt_c;

    // 문자열 stringstream 과 while 사용하면 stream에서 빼고 넣기 가능
    std::string text = "I have a deer, you too, have you.";
    int count = GetWordCount_OneWord("i", text);
    std::cout <<count << std::endl;

    vector<string> ls;
    ls.push_back("abc");
    ls.push_back("def");

    

}