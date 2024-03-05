#pragma once
#include <iostream>
#include <string>

class WordCounter{
    private:
        std::string text;
    public:
        //WordCounter(std::string atext = NULL);

        // get text input (only one sentence)
        void InputText(const std::string &text);
        // count word number
        int GetWordCount();
        // count character number except comma, period
        int GetCharacterCount();
        // count unique character(only comma, period)
        int GetUniqueWordCount();
        // count number of given char
        int GetWordCount_OneWord(const char*);

};
