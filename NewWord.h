#ifndef NEWWORD_H
#define  NEWWORD_H
#include <string>

class NewWord {
    private:
        std::string _newWord; //variable

    public:
        void addWord(const std::string& word); //method
        NewWord(const std::string& word); //constructor
};

#endif